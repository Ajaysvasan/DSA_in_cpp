#include <iostream>
#include <vector>

int climbStairsMemo(int n, std::vector<int> &memo) {
  if (n == 1 || n == 2) {
    return n;
  }

  if (memo[n] != -1) {
    return memo[n];
  }

  memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
  return memo[n];
}

int climbStairsTab(int n) {

  std::vector<int> dp(n + 1, -1);
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}
int climbStairsSO(int n) {
  int prevOne = 1;
  int prevTwo = 2;
  int current = 0;
  for (int i = 3; i <= n; i++) {
    current = prevOne + prevTwo;
    prevOne = prevTwo;
    prevTwo = current;
  }
  return current;
}

int climbStairs(int n) {
  if (n <= 0)
    return 0;

  std::vector<int> memo(n + 1, -1);

  return climbStairsSO(n);
}

int main(int argc, char *argv[]) {
  std::cout << climbStairs(4) << "\n";
  return 0;
}
