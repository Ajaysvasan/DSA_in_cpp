#include <bits/stdc++.h>
int dfs(std::vector<int> &arr, int target, std::vector<std::vector<int>> &dp,
        int idx) {
  if (target == 0)
    return 1;
  if (target < 0 || idx >= arr.size())
    return 0;
  if (dp[idx][target] != -1)
    return dp[idx][target];
  int take = dfs(arr, target - arr[idx], dp, idx + 1);
  int leave = dfs(arr, target, dp, idx + 1);
  return dp[idx][target] = take + leave;
}

int countWays(int target, std::vector<int> &arr) {
  std::vector<std::vector<int>> dp(arr.size(),
                                   std::vector<int>(target + 1, -1));
  return dfs(arr, target, dp, 0);
}

int countWaysTab(int target, std::vector<int> &arr) {
  std::vector<std::vector<int>> dp(arr.size() + 1,
                                   std::vector<int>(target + 1, 0));
  for (int i = 0; i <= arr.size(); i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= arr.size(); i++) {
    for (int j = 1; j <= target; j++) {
      if (arr[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
      }
    }
  }
  return dp[arr.size()][target];
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3, 3};
  int target = 6;
  std::cout << countWaysTab(target, arr);
  return 0;
}
