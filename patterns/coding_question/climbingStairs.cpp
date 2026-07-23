#include <iostream>
#include <vector>

//
// n = 2
// f(n){
//  if(n == 0){
//  return 1;
//  }
//  if(n < 0)
//  return 0
//  f(n - 1) + f(n-2)
// }

int helper(int n, std::vector<int> &dp) {
  if (n == 0) {
    return 1;
  }
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 1, -1);
  std::cout << helper(n, dp);
  return 0;
}
