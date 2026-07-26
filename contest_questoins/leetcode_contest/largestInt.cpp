#include <bits/stdc++.h>
class Solution {
  bool isValid(int n, int targetSum, int targetCount) {
    int sum = 0;
    int count = 0;
    while (n > 0) {
      count++;
      sum += (n % 10);
      n /= 10;
    }
    return (sum == targetSum && count == targetCount);
  }

public:
  int largestInteger(int n, int s) {
    if (s == 0)
      return 0;
    int end = 1 * (pow(10, n - 1));
    for (int start = pow(10, n) - 1; start >= end; start--) {
      if (isValid(start, s, n)) {
        return start;
      }
    }
    return -1;
  }
};
