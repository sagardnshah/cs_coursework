#include <iostream>
#include <mpi.h>
#include <chrono>
#include <math.h>
using namespace std;
#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: mpirun "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  int func_id = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  float n = atof(argv[4]);
  int intensity = atoi(argv[5]);

  float width = (b-a)/n;
  int gran = 100000;

  float final_result = 0;
  float* partial_sums;

  auto start = std::chrono::system_clock::now();
  MPI_Init (&argc, &argv);
  int rank, size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);
  partial_sums = new float[size];
  if(rank == 0){
    int curr_chunk = 0;
    while(curr_chunk != -1){
      for(int i = 1; i < size; i++){
        MPI_Send(&curr_chunk, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        curr_chunk += gran;
        if(curr_chunk >= n){
          curr_chunk = -1;
          for(int i = 1; i < size; i++){
            MPI_Send(&curr_chunk, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
          }
          for(int i = 1; i < size; i++){
            MPI_Recv(&(partial_sums[i]), 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          }
          break;
        }
      }
    }
  } else {
    int curr_chunk = 0;
    float node_sum = 0;
    while(curr_chunk != -1){
      MPI_Recv(&curr_chunk, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      if(curr_chunk != -1){
        int beg_i = curr_chunk;
        int end_i = curr_chunk + gran;
        if(end_i > n) end_i = n;
        for(int i = beg_i; i < end_i; i++){
          float x = a+((i+.5)*width);
          if(func_id == 1) node_sum += f1(x, intensity) * width;
          else if(func_id == 2) node_sum += f2(x, intensity) * width;
          else if(func_id == 3) node_sum += f3(x, intensity) * width;
          else if(func_id == 4) node_sum += f4(x, intensity) * width;
        }
      }
    }
    MPI_Send(&node_sum, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
  }
  if(rank == 0){
    for(int i = 1; i < size; i++) final_result += partial_sums[i];
  }
  MPI_Finalize();

  if(rank == 0){
    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout<<final_result<<endl;
    cerr<<elapsed_seconds.count()<<endl;
  }
  return 0;
}