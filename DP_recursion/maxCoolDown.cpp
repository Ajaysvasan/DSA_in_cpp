#include <bits/stdc++.h>
#include <vector>

int dfs(std::vector<int> &arr, int current_idx, int prev_idx,
        std::vector<std::vector<int>> &memo) {
  if (current_idx >= arr.size()) {
    return 0;
  }
  if (memo[current_idx][prev_idx + 1] != -1)
    return memo[current_idx][prev_idx + 1];
  int skip = dfs(arr, current_idx + 1, prev_idx, memo);
  int take = arr[current_idx] + dfs(arr, current_idx + 2, current_idx, memo);
  if (prev_idx != -1 && current_idx - prev_idx == 2) {
    return memo[current_idx][prev_idx + 1] = std::max(skip, take - 3);
  }
  return memo[current_idx][prev_idx + 1] = std::max(skip, take);
}

int maxCoolDown(std::vector<int> &arr) {
  std::vector<std::vector<int>> memo(arr.size(),
                                     std::vector<int>(arr.size() + 1, -1));
  return dfs(arr, 0, -1, memo);
}

int maxCoolDownTab(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<std::vector<int>> dp(arr.size() + 2,
                                   std::vector<int>(arr.size() + 1, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= -1; j--) {
      int skip = dp[i + 1][j + 1];
      int take = arr[i] + dp[i + 2][i + 1];
      if (j != -1 && i - j == 2) {
        dp[i][j + 1] = std::max(skip, take - 3);
      } else {
        dp[i][j + 1] = std::max(skip, take);
      }
    }
  }
  return dp[0][0];
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 2, 8, 3, 7, 6};
  std::cout << maxCoolDown(arr);
  return 0;
}
