#include <unistd.h>
#include <iostream>
using namespace std;
int main () {
  char name[64]; //hostname limited to 64 bytes
  gethostname(name, 64);
  cout << name;
  cout << '\n';
  return 0;
}
