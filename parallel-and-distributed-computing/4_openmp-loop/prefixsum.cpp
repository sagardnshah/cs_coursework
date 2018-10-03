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
void generatePrefixSumData (int* arr, size_t n);
void checkPrefixSumResult (int* arr, size_t n);
#ifdef __cplusplus
}
#endif

void prefixsum(int n, int nbthreads, int *arr, int *pr){
  pr[0]=0;
  omp_set_num_threads(nbthreads);

  //offset_arr will hold the offset for each thread
  int *offset_arr = new int[nbthreads+1];
  offset_arr[0]=0; //first thread won't need correction

  #pragma omp parallel
  {
    /**
     * each thread performs sequential prefix sum on
     * it's subarray
     */
    int subtotal=0;
    #pragma omp for schedule(static)
    for(int i=0; i<n; ++i){
      subtotal+=arr[i];
      pr[i+1]=subtotal;
    }

    /**
     * each thread will populate the offset array
     * with the correct offset for the next thread
     */
    int id = omp_get_thread_num();
    offset_arr[id+1] = subtotal;
    
    /**
     * wait for all other threads to reach here, then
     * calculate the sum up the offsets for each thread
     */
    #pragma omp barrier
    int thread_offset = 0;
    for(int i=0; i<=id; ++i){
      thread_offset += offset_arr[i];
    }

    /**
     * apply the correct offsets to each element
     * in the prefix array
     */
    #pragma omp for schedule(static)
    for(int i=0; i<n; ++i){
      pr[i+1]+=thread_offset;
    }
  }
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
  int nbthreads = atoi(argv[2]);
  int *arr = new int[n];
  generatePrefixSumData (arr, n);
  int *pr = new int[n+1];

  auto start = std::chrono::system_clock::now();
  prefixsum(n, nbthreads, arr, pr);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;

  checkPrefixSumResult(pr, n);
  delete[] arr;
  return 0;
}
