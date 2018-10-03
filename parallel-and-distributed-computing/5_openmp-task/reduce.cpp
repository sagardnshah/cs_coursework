#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
  void generateReduceData (int* arr, size_t n);
#ifdef __cplusplus
}
#endif

int *p_sums;

void reduce(int * arr, int n, int beg_i){
  int id = omp_get_thread_num();
  int p_sum = p_sums[id];
  int end_i = beg_i +100000;
  if(n<end_i){
    end_i = n;
  }
  for(int i = beg_i;i < end_i; i++){
        p_sum += arr[i];
    }
    p_sums[id] = p_sum;
}

int main (int argc, char* argv[]) {
  //forces openmp to create the threads beforehand
  #pragma omp parallel
  {
    int fd = open (argv[0], O_RDONLY);
    if (fd != -1) {
      close (fd);
    }
    else {
      std::cerr<<"something is amiss"<<std::endl;
    }
  }
  
  if (argc < 3) {
    std::cerr<<"Usage: "<<argv[0]<<" <n> <nbthreads>"<<std::endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int nbthreads = atoi (argv[2]);
  int * arr = new int [n];
  generateReduceData (arr, atoi(argv[1]));
  p_sums = new int[nbthreads+1];

  omp_set_num_threads(nbthreads);
  auto start = std::chrono::system_clock::now();
  #pragma omp parallel
  {
    #pragma omp single
    {
      int beg_i = 0;
      while(beg_i<n){
        #pragma omp task
        {
          reduce(arr, n, beg_i);
        }
        beg_i+=100000;
      }
      #pragma omp taskwait
    }
  }
  int result;
  for(int i=0;i<nbthreads;i++){
      result = result + p_sums[i];
  }
  auto end = std::chrono::system_clock::now();
  cout<<result<<endl;
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;

  delete[] arr;
  return 0;
}
