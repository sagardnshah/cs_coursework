#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <omp.h>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

  void generateMergeSortData (int* arr, size_t n);
  void checkMergeSortResult (const int* arr, size_t n);

#ifdef __cplusplus
}
#endif

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubblesort(int *arr, int n) {
  for (int i = 0; i<n;i++) {
    int k = i%2;
    #pragma omp parallel for default(none),shared(arr,k, n)
    for (int j = k; j<n-1; j+=2) {
      if (arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
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
  
  if (argc < 3) { std::cerr<<"usage: "<<argv[0]<<" <n> <nbthreads>"<<std::endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int nbthreads = atoi(argv[2]);
  
  int * arr = new int [n];
  generateMergeSortData (arr, n);

  omp_set_num_threads(nbthreads);
  auto start = std::chrono::system_clock::now();
  bubblesort(arr, n);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;
  checkMergeSortResult (arr, n);
  delete[] arr;
  return 0;
}
