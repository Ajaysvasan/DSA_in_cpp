#include <bits/stdc++.h>
using namespace std;

int countOnes(int n) {
  int count = 0;
  while (n > 0) {
    int rem = n % 2;
    count += rem;
    n = n / 2;
  }
  return count;
}

int main(int argc, char *argv[]) {
  int n = 15;
  cout << countOnes(n);
  return 0;
}
