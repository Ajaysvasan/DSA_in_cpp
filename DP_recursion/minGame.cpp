#include <bits/stdc++.h>

int dfs(std::vector<int> &arr, int left, int right,
        std::vector<std::vector<int>> &dp) {
  if (left > right) {
    return 0;
  }
  if (left == right) {
    return arr[left];
  }
  if (dp[left][right] != -1)
    return dp[left][right];
  return dp[left][right] = std::max(arr[left] - dfs(arr, left + 1, right, dp),
                                    arr[right] - dfs(arr, left, right - 1, dp));
}
bool minGameTab(std::vector<int> &arr) {
  int n = arr.size();

  // dp[i][j] stores the max score difference a player can get from arr[i...j]
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

  // Base case: When left == right (subarrays of length 1)
  // You just take the single available element.
  for (int i = 0; i < n; i++) {
    dp[i][i] = arr[i];
  }

  // DP Transitions:
  // 'left' iterates backwards so dp[left + 1] is already calculated
  for (int left = n - 1; left >= 0; left--) {
    // 'right' iterates forwards starting just after 'left'
    for (int right = left + 1; right < n; right++) {

      int take_left = arr[left] - dp[left + 1][right];
      int take_right = arr[right] - dp[left][right - 1];

      dp[left][right] = std::max(take_left, take_right);
    }
  }

  // The result for the full array (from index 0 to n - 1)
  return dp[0][n - 1] >= 0;
}
bool minGame(std::vector<int> &arr) {
  std::vector<std::vector<int>> dp(arr.size(),
                                   std::vector<int>(arr.size(), -1));
  return dfs(arr, 0, arr.size() - 1, dp) >= 0 ? true : false;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 5, 233, 7};
  if (minGameTab(arr)) {
    std::cout << "True\n";
  } else {
    std::cout << "False\n";
  }
  return 0;
}
