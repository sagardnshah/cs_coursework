#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <mpi.h>

using namespace std;

float genA (long row, long col) {
  if (row > col)
    return 1.;
  else
    return 0.;
}

float genx0 (int i) {
  return 1.;
}

void checkx (int iter, long i, float xval) {
  if (iter == 1) {
    float shouldbe = i;
    if (fabs(xval/shouldbe) > 1.01 || fabs(xval/shouldbe) < .99 )
      std::cout<<"incorrect : x["<<i<<"] at iteration "<<iter<<" should be "<<shouldbe<<" not "<<xval<<std::endl;
  }

  if (iter == 2) {
    float shouldbe =(i-1)*i/2;
    if (fabs(xval/shouldbe) > 1.01 || fabs(xval/shouldbe) < .99)
      std::cout<<"incorrect : x["<<i<<"] at iteration "<<iter<<" should be "<<shouldbe<<" not "<<xval<<std::endl;
  }
}

//perform dense y=Ax on an n \times n matrix
void matmul(float*A, float*x, float*y, long n) {
  for (long row = 0; row<n; ++row) {
    float sum = 0;
    for (long col = 0; col<n; ++col) {
      //sum += x[col] *A[row][col]
      sum += x[col] * A[row*n+col];
    }
    y[row] = sum;
  }
}

int main (int argc, char*argv[]) {

  if (argc < 3) {
    std::cout<<"usage: "<<argv[0]<<" n iteration"<<std::endl;
  }
  
  bool check = false;
  long n = atol(argv[1]);
  long iter = atol(argv[2]);
  
  auto start = std::chrono::system_clock::now();
  MPI_Init(&argc, &argv);

  //world_comm
  int world_rank, world_size;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  //row comm
  int row_c = world_rank / sqrt(world_size);
  MPI_Comm row_comm;
  MPI_Comm_split(MPI_COMM_WORLD, row_c, world_rank, &row_comm);
  int row_rank, row_size;
  MPI_Comm_rank(row_comm, &row_rank);
  MPI_Comm_size(row_comm, &row_size);

  //col comm
  int col_c = row_rank;
  MPI_Comm col_comm;
  MPI_Comm_split(MPI_COMM_WORLD, col_c, world_rank, &col_comm);
  int col_rank, col_size;
  MPI_Comm_rank(col_comm, &col_rank);
  MPI_Comm_size(col_comm, &col_size);

  //calculate starting row & col indices for each node
  //generate submatrix A for each node
  float subA_row_start = (float) n*((float) col_rank / (float) col_size);
  float subA_col_start = (float) n*((float) row_rank / (float) col_size);
  long subA_size = (n/sqrt(world_size))*(n/sqrt(world_size));
  float* subA = new float[subA_size];
  long subA_index=0;
  for(long row_index = subA_row_start; row_index < (subA_row_start+(n / row_size)); ++row_index){
    for(long col_index = subA_col_start; col_index < (subA_col_start+(n / col_size)); ++col_index){
      subA[subA_index] = genA(row_index, col_index);
      subA_index++;
    }
  }

  //generate subvector x0 for each node
  //subA * subx0 = suby
  long subx0_size = n/sqrt(world_size);
  float* subx0 = new float[subx0_size];
  for(long i = 0; i < subx0_size; ++i){
    subx0[i] = genx0(i);
  }

  //initialize suby for each node
  float* suby = new float[subx0_size];

  //rowy stores the row reduction of subx0
  float* rowy = new float[subx0_size];

  for(int i = 0; i < iter; ++i){
    //matric vector product
    //subA * subx0 = suby
    matmul(subA, subx0, suby, subx0_size);

    //reduce suby into rowy across all row communicators
    MPI_Allreduce(suby, rowy, subx0_size, MPI_FLOAT, MPI_SUM, row_comm);

    //swap subx0 with suby
    //so that during the next iteration matmul gets the correct subx0
    float*t = subx0;
    subx0=rowy;
    rowy=t;

    //broadcast the result of row reduce from nodes in the diagnol
    //to all nodes in the col communicator for the correct subx0 for next matmul iteration
    MPI_Bcast(subx0, subx0_size, MPI_FLOAT, row_rank, col_comm);

    if(check)
      for (long j = 0; j<subx0_size; ++j)
	    checkx (i+1, row_rank*subx0_size+j, subx0[j]);
  }
  
  delete[] subA;
  delete[] subx0;
  delete[] suby;
  delete[] rowy;
  MPI_Finalize();
  
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  if(world_rank == 0 ){
    std::cerr<<elapsed_seconds.count()<<std::endl;
  }
  return 0;
}
