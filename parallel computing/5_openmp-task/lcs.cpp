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

  void generateLCS(char* X, int m, char* Y, int n);
  void checkLCS(char* X, int m, char* Y, int n, int result);

#ifdef __cplusplus
}
#endif

int nbthreads;

int LCS(char* X, int m, char* Y, int n) {
  omp_set_num_threads(nbthreads);
  int** C = new int*[m+1];
  #pragma omp paralell for schedule(static)
  for (int i=0; i<=m; ++i) {
    C[i] = new int[n+1];
    C[i][0] = 0;
  }
  #pragma omp paralell for schedule(static)
  for (int j=0; j<=n; ++j) {
    C[0][j] = 0;
  }
  
  #pragma omp paralell for collpase(2) schedule(static)
  for (int a=1; a<=m; ++a) {
    for (int b=1; b<=n; ++b) {
      if (X[a-1] == Y[b-1]) {
        C[a][b] = C[a-1][b-1] + 1; 
      } else {
        C[a][b] = std::max(C[a-1][b], C[a][b-1]);
      }
    }
  }
  int result = C[m][n];
  #pragma omp paralell for schedule(static)
  for (int i=0; i<=m; ++i) { 
    delete[] C[i];
  }
  delete[] C;
  
  return result;
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

  if (argc < 4) { std::cerr<<"usage: "<<argv[0]<<" <m> <n> <nbthreads>"<<std::endl;
    return -1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  nbthreads = atoi(argv[3]);

  // get string data 
  char *X = new char[m];
  char *Y = new char[n];
  generateLCS(X, m, Y, n);

  
  auto start = std::chrono::system_clock::now();
  int result = LCS(X, m, Y, n);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl;

  checkLCS(X, m, Y, n, result);

  return 0;
}
