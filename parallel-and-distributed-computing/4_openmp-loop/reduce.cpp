#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <chrono>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

void generateReduceData (int* arr, size_t n);

#ifdef __cplusplus
}
#endif

void reduce(char* argv[], int* arr){
  int result = 0;
  #pragma omp parallel for schedule(runtime) reduction(+:result)
  for(int i=0; i<atoi(argv[1]); ++i){
    result+=arr[i];
  }
  cout<<result<<endl;
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
      cerr<<"something is amiss"<<endl;
    }
  }  
  if (argc < 5) {
    cerr<<"Usage: "<<argv[0]<<" <n> <nbthreads> <scheduling> <granularity>"<<endl;
    return -1;
  }
  int * arr = new int [atoi(argv[1])];
  generateReduceData (arr, atoi(argv[1]));
  omp_set_num_threads(atoi(argv[2]));
  string sched = argv[3];
  int gran = atoi(argv[4]);

  if(!sched.compare("static")){
    omp_set_schedule(omp_sched_static, gran);
  }
  else if(!sched.compare("dynamic")){
    omp_set_schedule(omp_sched_dynamic, gran);
  }
  else if(!sched.compare("guided")){
    omp_set_schedule(omp_sched_guided, gran);
  }

  auto start = std::chrono::system_clock::now();
  reduce(argv, arr);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cerr<<elapsed_seconds.count()<<endl; 
  
  delete[] arr;
  return 0;
}
