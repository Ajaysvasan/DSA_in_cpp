#include <bits/stdc++.h>
using namespace std;

const int n = 16;
int fen[n];

void update(int i, int add) {
  while (i < n) {
    fen[i] += add;
    i = i + (i & -i);
  }
}

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += fen[i];
    i = i - (i & -i);
  }
  return s;
}
