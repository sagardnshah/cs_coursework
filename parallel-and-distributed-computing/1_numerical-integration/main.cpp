#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <unistd.h>

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

  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  float func_id = atof(argv[1]);
  float a = atof(argv[2]);
  float b = atof(argv[3]);
  float n = atof(argv[4]);
  int intensity = atoi(argv[5]);

  float result = 0;

  auto start = chrono::steady_clock::now();
  
  if(func_id == 1){
    for(int i=0; i<n; i++){
      result+=(f1(((a+i+.5)*((b-a)/n)),intensity))*((b-a)/n);
    }
  }
  else if(func_id == 2){
    for(int i=0; i<n; i++){
       result+=(f2(((a+i+.5)*((b-a)/n)),intensity))*((b-a)/n);
    }
  }
  else if(func_id == 3){
    for(int i=0; i<n; i++){
      result+=(f3(((a+i+.5)*((b-a)/n)),intensity))*((b-a)/n);
    }
  }
  else if(func_id == 4){
    for(int i=0; i<n; i++){
       result+=(f4(((a+i+.5)*((b-a)/n)),intensity))*((b-a)/n);
    }
  }

auto end = chrono::steady_clock::now();

cout << result;
cerr << chrono::duration_cast<chrono::seconds>(end-start).count();
  return 0;
}
