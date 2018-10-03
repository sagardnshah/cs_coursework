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

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

float numint(char* argv[]){
  int func_id = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  int n = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  omp_set_num_threads(atoi(argv[6]));
  string sched = argv[7];
  int granularity = atoi(argv[8]);

  float result = 0;
  float width = (b-a)/(float)n;

  if(!sched.compare("static")){
    omp_set_schedule(omp_sched_static, granularity);
  }
  else if(!sched.compare("dynamic")){
    omp_set_schedule(omp_sched_dynamic, granularity);
  }
  else if(!sched.compare("guided")){
    omp_set_schedule(omp_sched_guided, granularity);
  }

  if(func_id == 1){
    #pragma omp parallel for reduction(+:result)
    for(int i=0; i<n; i++){
      result+=f1(a+(i+.5)*width,intensity)*width;
    }
  }
  else if(func_id == 2){
    #pragma omp parallel for reduction(+:result)
    for(int i=0; i<n; i++){
      result+=f2(a+(i+.5)*width,intensity)*width;
    }
  }
  else if(func_id == 3){
    #pragma omp parallel for reduction(+:result)
    for(int i=0; i<(int)n; i++){
      result+=f3(a+(i+.5)*width,intensity)*width;
    }
  }
  else if(func_id == 4){
    #pragma omp parallel for reduction(+:result)
    for(int i=0; i<n; i++){
      result+=f4(a+(i+.5)*width,intensity)*width;
    }
  }
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
  
  if (argc < 9) {
    std::cerr<<"Usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity> <nbthreads> <scheduling> <granularity>"<<std::endl;
    return -1;
  }

  auto start = std::chrono::system_clock::now();
  float result = numint(argv);
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cout<<result<<endl;
  cerr<<elapsed_seconds.count()<<endl;
  return 0;
}
