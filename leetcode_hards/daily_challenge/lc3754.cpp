#include <iostream>
#include <ostream>
class Solution {
public:
  long long sumAndMultiply(int n) {
    long long x = 0;
    long long sum = 0;
    long long power = 1;
    while (n > 0) {
      int rem = n % 10;
      // std::cout << rem << std::endl;
      if (rem >= 1) {
        x = x + (rem * power);
        sum += rem;
        power *= 10;
      }
      n /= 10;
    }
    return sum * x;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  int n = 10203040;
  std::cout << sol.sumAndMultiply(n);
  return 0;
}
