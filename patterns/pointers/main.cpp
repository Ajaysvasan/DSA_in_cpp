#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int a = 10;
  int *b = &a;
  float x = 10.0;
  printf("%f", x);
  const char *str = "python";
  printf("%c", *str);
  printf("\n%p", b);
  return 0;
}
