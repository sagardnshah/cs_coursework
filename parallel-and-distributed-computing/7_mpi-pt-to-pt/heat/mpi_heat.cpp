#include <mpi.h>
#include <math.h>
#include <iostream>


#ifdef __cplusplus
extern "C" {
#endif

  void generate2DHeat(double** H, long n, long rank, long P); //this assumes array of array and grid block decomposition
  int check2DHeat(double** H, long n, long rank, long P, long k); //this assumes array of array and grid block decomposition

#ifdef __cplusplus
}
#endif



int main(int argc, char* argv[]) {

  if (argc < 3) {
    std::cerr<<"usage: mpirun "<<argv[0]<<" <N> <K>"<<std::endl;
    return -1;
  }

  // declare and init command line params
  long N, K;
  N = atol(argv[1]);
  K = atol(argv[2]);

  // use double for heat 2d 

  // write code here


  return 0;
}

