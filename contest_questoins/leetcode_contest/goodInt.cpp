#include <bits/stdc++.h>
class Solution {
  int digitSum(int n) {
    int temp = n;
    int sum = 0;
    while (n > 0) {
      int rem = n % 10;
      n = n / 10;
      sum += rem;
    }
    return sum;
  }
  int squareDigit(int n) {
    int temp = n;
    long long sum = 0;
    while (n > 0) {
      int rem = n % 10;
      n = n / 10;
      sum += (rem * rem);
    }
    return sum;
  }

  // sum = 5 + 6 = 11
  // suare = 36 + 25 = 61
  // 61 - 11 = 50

public:
  bool checkGoodInteger(int n) { return (squareDigit(n) - digitSum(n) >= 50); }
};

int main(int argc, char *argv[]) {
  Solution s;
  int n = 56;
  std::cout << s.checkGoodInteger(n);
  return 0;
}
