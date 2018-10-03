#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <omp.h>
#include <chrono>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
  void generateMergeSortData (int* arr, size_t n);
  void checkMergeSortResult (int* arr, size_t n);
#ifdef __cplusplus
}
#endif

void merge(int * arr, int l, int mid, int r){
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

void mergesort(int *a, int n){
  for(int i=1; i<=n-1; i=2*i){
	  #pragma omp parallel for schedule(static)
		for (int j=0; j<n-1; j+=2*i){
      //int id = omp_get_thread_num();
      int middle, right;

      if((j+i-1)<n-1){
        middle = j+i-1;
      }
      else middle = n-1;

      if((j+(2*i)-1)<n-1){
        right = j+(2*i)-1;
      }
      else right = n-1;

			merge(a, j, middle, right);
      //cout<<id<<", "<<j<<", "<<endl;
      //cout<<id<<", ";
		}
    //cout<<i<<", ";
    //cout<<endl;
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
  omp_set_num_threads(atoi(argv[2]));
  
  // get arr data
  int * arr = new int [n];
  generateMergeSortData (arr, n);

  /**
   * print unsorted array
  for(int i=0; i<n; ++i){
    cout<<arr[i]<<", ";
  }
  cout<<endl;
  */

  //insert sorting code here.
  auto start = std::chrono::system_clock::now();
  mergesort(arr, n);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;

  /**
   * print sorted array
  for(int i=0; i<n; ++i){
    cout<<arr[i]<<", ";
  }
  cout<<endl;
  */
  
  checkMergeSortResult (arr, n);
  
  delete[] arr;

  return 0;
}
