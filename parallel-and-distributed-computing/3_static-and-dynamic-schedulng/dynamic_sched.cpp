#include <iostream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Range.h"
#include <queue>
#include <pthread.h>
#include <cmath>

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

pthread_mutex_t mut;

int chunk;
int num_chunks;
struct chunk_PARAMS{
  int func_id;
  float a;
  float b;
  int n;
  int intensity;
  float* result;
  bool partial_chunk;
  int beg_i;
  int end_i;
  int gran;
};

bool done(){
  pthread_mutex_lock(&mut);
  bool d = false;
  if(!(chunk<num_chunks)){
    d=true;
  }
  pthread_mutex_unlock(&mut);
  return d;
}

int getNext(){
  pthread_mutex_lock(&mut);
  int c = -1;
  if(chunk<num_chunks){
    c = chunk;
    chunk++;
  }
  pthread_mutex_unlock(&mut);
  return c;
}

void* dynamic_iteration_level(void* para){
  chunk_PARAMS* values = (chunk_PARAMS*) para;
  chunk_PARAMS p = (chunk_PARAMS) *values;
  int curr_chunk, beg, end;
  while(!done()){
  float temp_result=0;
    curr_chunk = getNext();
    if(curr_chunk == -1){
      break;
    }
    beg = curr_chunk * p.gran;
    if(p.n%p.gran!=0 && curr_chunk==num_chunks-1){
      end = p.n-1;
    }
    else{
      end = beg + p.gran - 1;
    }

    if(p.func_id == 1){
      for(int i=beg; i<=end; ++i){
        temp_result=(f1(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
        pthread_mutex_lock(&mut);
        if(curr_chunk < num_chunks){
          *values->result+=temp_result;
        }
        pthread_mutex_unlock(&mut);
      }
    }
    if(p.func_id == 2){
      for(int i=beg; i<=end; ++i){
        temp_result=(f2(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
        pthread_mutex_lock(&mut);
        if(curr_chunk < num_chunks){
          *values->result+=temp_result;
        }
        pthread_mutex_unlock(&mut);
      }
    }
    if(p.func_id == 3){
      for(int i=beg; i<=end; ++i){
        temp_result=(f3(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
        pthread_mutex_lock(&mut);
        if(curr_chunk < num_chunks){
          *values->result+=temp_result;
        }
        pthread_mutex_unlock(&mut);
      }
    }
    if(p.func_id == 4){
      for(int i=beg; i<=end; ++i){
        temp_result=(f4(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
        pthread_mutex_lock(&mut);
       if(curr_chunk < num_chunks){
          *values->result+=temp_result;
        }
        pthread_mutex_unlock(&mut);
      }
    }
  }
  return NULL;
}

void* dynamic_thread_level(void* para){
  chunk_PARAMS* values = (chunk_PARAMS*) para;
  chunk_PARAMS p = (chunk_PARAMS) *values;
  float partial_result=0;
  int curr_chunk, beg, end;
  while(!done()){
    curr_chunk = getNext();
    if(curr_chunk == -1){
      break;
    }
    beg = curr_chunk * p.gran;
    if(p.n%p.gran!=0 && curr_chunk==num_chunks-1){
      end = p.n-1;
    }
    else{
      end = beg + p.gran - 1;
    }
    if(p.func_id == 1){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f1(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 2){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f2(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 3){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f3(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 4){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f4(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
  }
    pthread_mutex_lock(&mut);
    if(curr_chunk < num_chunks){
    *values->result+=partial_result;
     }
    pthread_mutex_unlock(&mut);
    return NULL; 
}
void* dynamic_chunk_level(void* para){
  chunk_PARAMS* values = (chunk_PARAMS*) para;
  chunk_PARAMS p = (chunk_PARAMS) *values;
  float partial_result=0;
  int curr_chunk, beg, end;
  while(!done()){
    curr_chunk = getNext();
    if(curr_chunk == -1){
      break;
    }
    beg = curr_chunk * p.gran;
    if(p.n%p.gran!=0 && curr_chunk==num_chunks-1){
      end = p.n-1;
    }
    else{
      end = beg + p.gran - 1;
    }
    if(p.func_id == 1){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f1(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 2){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f2(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 3){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f3(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    if(p.func_id == 4){
      for(int i=beg; i<=end; ++i){
        partial_result+=(f4(((p.a+i+.5)*((p.b-p.a)/ p.n)),p.intensity))*((p.b-p.a)/ p.n);
      }
    }
    pthread_mutex_lock(&mut);
    if(curr_chunk < num_chunks){
    *values->result+=partial_result;
    partial_result = 0;
    }
    pthread_mutex_unlock(&mut);
  }
  //pthread_mutex_lock(&mut);
  //if(curr_chunk < num_chunks){
  //    *values->result+=partial_result;
  //  }
  //  pthread_mutex_unlock(&mut);
  return NULL;
}
int main (int argc, char* argv[]) {

  if (argc < 9) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity> <nbthreads> <sync> <granularity>"<<std::endl;
    return -1;
  }

  int func_id = atoi(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  int n = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  int nbthreads = atoi(argv[6]);
  string sync = argv[7];
  int granularity = atoi(argv[8]);
  float result = 0;

  //CHUNK DATA PREP
  //BEGIN
  bool partial_chunk = false;
  int chunk = 1; //initial chunk index
  //calculate numer of chunks
  if(granularity < n){
    num_chunks = n/granularity;
    if(n%granularity != 0){
      partial_chunk = true;
      num_chunks++;
    }
  }
  else {
    num_chunks=1;
  }
  //each thread will be passed a static params
  chunk_PARAMS *s = new chunk_PARAMS[nbthreads];
  for(int i=0; i<nbthreads; ++i){
    s[i].func_id = func_id;
    s[i].a = a;
    s[i].b = b;
    s[i].n = n;
    s[i].intensity = intensity;
    s[i].result = &result;
    s[i].partial_chunk = partial_chunk;
    //these begin and end are not for each chunk
    //these are ALL the indices
    s[i].beg_i = 0;
    s[i].end_i = n-1;
    s[i].gran = granularity;
  }

  pthread_t threads[nbthreads];
  auto start = std::chrono::system_clock::now();
  if(!sync.compare("chunk")){
    for(int i=0; i<nbthreads; ++i){
      pthread_create(&threads[i], NULL, dynamic_chunk_level, (void*) &s[i]);
    }
  }
  if(!sync.compare("iteration")){
    for(int j=0; j<nbthreads; ++j){
      pthread_create(&threads[j], NULL, dynamic_iteration_level, (void*) &s[j]);
    }
  }
  if(!sync.compare("thread")){
    for(int k=0; k<nbthreads; ++k){
      pthread_create(&threads[k], NULL, dynamic_thread_level, (void*) &s[k]);
    }
  }
  for(int l=0; l<nbthreads; ++l){
      pthread_join(threads[l], NULL);
  }
  auto end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end-start;
  cout<<result;
  cout<<endl;
  cerr<<elapsed_seconds.count();
  cout<<endl;
  
  return 0;
}
