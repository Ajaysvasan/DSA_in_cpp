#include <algorithm>
#include <iostream>
#include <vector>

int dfs(std::vector<int> &arr, int idx, int prev_idx,
        std::vector<std::vector<int>> &memo) {
  if (idx == arr.size())
    return 0;
  if (memo[idx][prev_idx + 1] != -1)
    return memo[idx][prev_idx + 1];
  int len = 0 + dfs(arr, idx + 1, prev_idx, memo);
  if (prev_idx == -1 || arr[idx] > arr[prev_idx]) {
    len = std::max(len, 1 + dfs(arr, idx + 1, idx, memo));
  }
  return memo[idx][prev_idx + 1] = len;
}

int lisMemo(std::vector<int> &arr) {
  std::vector<std::vector<int>> memo(arr.size(),
                                     std::vector<int>(arr.size() + 1, -1));
  return dfs(arr, 0, -1, memo);
}

int lis(std::vector<int> &arr) {
  std::vector<std::vector<int>> dp(arr.size() + 1,
                                   std::vector<int>(arr.size() + 1, 0));
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= -1; j--) {
      int len = 0 + dp[i + 1][j + 1];
      if (j == -1 || arr[i] > arr[j]) {
        len = std::max(len, 1 + dp[i + 1][i + 1]);
      }
      dp[i][j + 1] = len;
    }
  }
  return dp[0][0];
}

int lisSo(std::vector<int> &arr) {
  std::vector<int> dp(arr.size(), 1);
  int maxLength = -1;
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j])
        dp[i] = std::max(dp[i], dp[j] + 1);
    }
    maxLength = std::max(maxLength, dp[i]);
  }
  return maxLength;
}
int main(int argc, char *argv[]) {
  std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
  std::cout << "The maximum length is : " << lisSo(arr) << "\n";
  return 0;
}
