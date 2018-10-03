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
  void checkMergeSortResult (int* arr, size_t n);
#ifdef __cplusplus
}
#endif

void merge(int * arr, int l, int mid, int r) {
  
  int i, j, k;
  int n = mid - l + 1;
  int m = r - mid;
  
  // declare and init temp arrays
  int *L = new int[n];
  int *R = new int[m];
  for (i=0; i<n; ++i)
    L[i] = arr[l+i];
  for (j=0; j<m; ++j)
    R[j] = arr[mid+1+j];

  // init indicies
  i = 0;
  j = 0;
  k = l;

  // fill arr with least value at current position in tempL or tempR
  while (i<n && j<m) {
    arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
  }

  // ensure tempL was competely copied
  while (i<n) {
    arr[k++] = L[i++];
  }

  // ensure tempR was competely copied
  while (j<m) {
    arr[k++] = R[j++];
  }

  // de-allocate structs used
  delete[] L;
  delete[] R;

}

void mergesort(int *arr, int l, int r){
  if(l<r){
    int m = (l+r)/2;
    
    #pragma omp task
    mergesort(arr, l, m);

    #pragma omp task
    mergesort(arr, m+1, r);

    #pragma omp taskwait
    merge(arr, l, m, r);
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
  
  if (argc < 3) { std::cerr<<"Usage: "<<argv[0]<<" <n> <nbthreads>"<<std::endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int nbthreads = atoi(argv[2]);
  int * arr = new int [n];
  generateMergeSortData (arr, n);

  omp_set_num_threads(nbthreads);

  auto start = std::chrono::system_clock::now();
  #pragma omp parallel
  {
    #pragma omp single
    {
      mergesort(arr, 0, n-1);
    }
  }
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;
  
  checkMergeSortResult (arr, n);
  delete[] arr;
  return 0;
}
