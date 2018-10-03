#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <cmath>
#include <pthread.h>

using namespace std;

pthread_mutex_t mut;

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

struct PARAMS{
  int func_id;
  float a;
  float b;
  float n;
  int intensity;
  float* results;
  int beg_i; //starting index for thread
  int end_i;
  float partial_result; //only used by thread_level()
};

void* iteration_level(void* para){
  PARAMS* p = (PARAMS*) para;
  float temp_result = 0;
  if(p->func_id == 1){
    for(int i=p->beg_i; i<=p->end_i; ++i){
      temp_result=(f1(((p->a+i+.5)*((p->b-p->a)/ p->n)),p->intensity))*((p->b-p->a)/ p->n);
      pthread_mutex_lock(&mut);
      *p->results+=temp_result;
      pthread_mutex_unlock(&mut);
    }
  }
  else if(p->func_id == 2){
    for(int i=p->beg_i; i<=p->end_i; ++i){
      temp_result=(f2(((p->a+i+.5)*((p->b-p->a)/ p->n)),p->intensity))*((p->b-p->a)/ p->n);
      pthread_mutex_lock(&mut);
      *p->results+=temp_result;
      pthread_mutex_unlock(&mut);
    }
  }
  else if(p->func_id == 3){
    for(int i=p->beg_i; i<=p->end_i; ++i){
      temp_result=(f3(((p->a+i+.5)*((p->b-p->a)/ p->n)),p->intensity))*((p->b-p->a)/ p->n);
      pthread_mutex_lock(&mut);
      *p->results+=temp_result;
      pthread_mutex_unlock(&mut);
    }
  }
  else if(p->func_id == 4){
    for(int i=p->beg_i; i<=p->end_i; ++i){
      temp_result=(f4(((p->a+i+.5)*((p->b-p->a)/ p->n)),p->intensity))*((p->b-p->a)/ p->n);
      pthread_mutex_lock(&mut);
      *p->results+=temp_result;
      pthread_mutex_unlock(&mut);
    }
  }

  return NULL;
}

void* thread_level(void* para){
  PARAMS* values = (PARAMS*) para;
  PARAMS p = (PARAMS) *values;
  if(p.func_id == 1){
    for(int i=p.beg_i; i<=p.end_i; ++i){
      p.partial_result+=(f1(((p.a+i+.5)*((p.b-p.a)/p.n)),p.intensity))*((p.b-p.a)/p.n);
    }
  }
  else if(p.func_id == 2){
    for(int i=p.beg_i; i<=p.end_i; ++i){
      p.partial_result+=(f2(((p.a+i+.5)*((p.b-p.a)/p.n)),p.intensity))*((p.b-p.a)/p.n);
    }
  }
  else if(p.func_id == 3){
    for(int i=p.beg_i; i<=p.end_i; ++i){
      p.partial_result+=(f3(((p.a+i+.5)*((p.b-p.a)/p.n)),p.intensity))*((p.b-p.a)/p.n);
    }
  }
  else if(p.func_id == 4){
    for(int i=p.beg_i; i<=p.end_i; ++i){
      p.partial_result+=(f4(((p.a+i+.5)*((p.b-p.a)/p.n)),p.intensity))*((p.b-p.a)/p.n);
    }
  }
  pthread_mutex_lock(&mut);
  *values->results+=p.partial_result;
  pthread_mutex_unlock(&mut);
  return NULL;
}

int main (int argc, char* argv[]) {

  if (argc < 8) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity> <nbthreads> <sync>"<<std::endl;
    return -1;
  }
  
  int func_id = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  float n = atof(argv[4]);
  int intensity = atoi(argv[5]); 
  int nbthreads = atoi(argv[6]);
  string sync = argv[7];
  float result = 0;
  
  //sometimes number of points (n) divided by number of threads won't result a whole number
  float precise_work_per_thread = n/nbthreads;
  int work_per_thread = floor(n/nbthreads);
  
  //an extra thread will be used when work can't be distributed evenly across threads
  bool extra_thread=false;
  if(precise_work_per_thread >(float)work_per_thread){
    extra_thread=true;
  }
  PARAMS *p;
  int current_thread = 0;
  int current_thread_beg_i = 0;
  int current_thread_end_i = current_thread_beg_i + work_per_thread -1;
  if(extra_thread){
    p=new PARAMS[nbthreads+1];
    for(int i=0; i<nbthreads; ++i){
      p[i].func_id = func_id;
      p[i].a = a;
      p[i].b = b;
      p[i].n = n;
      p[i].intensity = intensity;
      p[i].results = &result;
      p[i].beg_i = current_thread_beg_i;
      p[i].end_i = current_thread_beg_i + work_per_thread-1;
      current_thread_beg_i += work_per_thread;
    }
    p[nbthreads].func_id = func_id;
    p[nbthreads].a = a;
    p[nbthreads].b = b;
    p[nbthreads].n = n;
    p[nbthreads].intensity = intensity;
    p[nbthreads].results = &result;
    p[nbthreads].beg_i = current_thread_beg_i;
    p[nbthreads].end_i = n-1;

    nbthreads++;
  }
  else {
    p=new PARAMS[nbthreads];
    for(int i=0; i<nbthreads; ++i){
      p[i].func_id = func_id;
      p[i].a = a;
      p[i].b = b;
      p[i].n = n;
      p[i].intensity = intensity;
      p[i].results = &result;
      p[i].beg_i = current_thread_beg_i;
      p[i].end_i = current_thread_beg_i + work_per_thread-1;
      current_thread_beg_i += work_per_thread;
    }
  }
  
  pthread_t threads[nbthreads];
  auto start = std::chrono::system_clock::now();
  //iteration-level parallelism
  if(!sync.compare("iteration")){
    for(int i=0; i<nbthreads; ++i){
      pthread_create(&threads[i], NULL, iteration_level,(void*) &p[i]);
    }
    for(int i=0; i<nbthreads; ++i){
      pthread_join(threads[i], NULL);
    }
  }
  //thread-level parallelism
  else if("thread"){
    for(int i=0; i<nbthreads; ++i){
      pthread_create(&threads[i], NULL, thread_level,(void*) &p[i]);
    }
    for(int i=0; i<nbthreads; ++i){
      pthread_join(threads[i], NULL);      
    }
  }
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cout<<result;
  cerr<<elapsed_seconds.count();
  return 0;
}
