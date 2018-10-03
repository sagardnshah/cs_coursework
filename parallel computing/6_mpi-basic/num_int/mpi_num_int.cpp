#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <mpi.h>

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
		std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
		return -1;
  }

	int func_id = atoi(argv[1]);
	float a = atoi(argv[2]);
	float b = atoi(argv[3]);
	int n = atoi(argv[4]);
	int intensity = atoi(argv[5]);
    
	auto start = std::chrono::system_clock::now();
	
	MPI_Init(&argc, &argv);

	int rank, size;
	float x, y, p_sum;
	p_sum = 0;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

  float width = (b-a)/n;
  float work = n/size;

	for (int i = 0; i < work; ++i) {
		int node_i = i+rank*work;
		x = a+node_i+0.5*width;

    if (func_id == 1) p_sum += width * f1(x, intensity);
		else if (func_id == 2) p_sum += width * f2(x, intensity);
		else if (func_id == 3) p_sum += width * f3(x, intensity);
		else if (func_id == 4) p_sum += width * f4(x, intensity);
	}
	float result;
	MPI_Allreduce(&p_sum, &result, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
	MPI_Finalize();

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsedSeconds = end-start;
  if(rank==0){
    cout<<result;
	  cerr<<elapsedSeconds.count();
  }
  return 0;
}
