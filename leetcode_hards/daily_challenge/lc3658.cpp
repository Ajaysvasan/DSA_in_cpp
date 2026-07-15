#include <bits/stdc++.h>
using namespace std;
class Solution {
  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  int gcdOfOddEvenSumsOneWay(int n) {
    int sumEven = 0, sumOdd = 0;
    for (int i = 1; i <= n; i++) {
      // 2 , 4, 6 , 8 - > 2 + 4 + 6 + 8 = 20
      sumEven += i * 2;
    }
    // for odd 2 n - 1 form
    for (int i = 1; i <= n; i++) {
      int oddValue = (2 * i) - 1;
      sumOdd += oddValue;
    }
    return gcd(sumOdd, sumEven);
  }

public:
  int gcdOfOddEvenSums(int n) {
    // Optimal solution
    return n;
  }
};
