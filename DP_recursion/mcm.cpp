#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int dfs(std::vector<int> &arr, int start, int end,
        std::vector<std::vector<int>> &dp) {
  if (start == end)
    return 0;
  if (dp[start][end] != -1)
    return dp[start][end];
  int minimum = INT_MAX;
  for (int i = start; i < end; i++) {
    int steps = arr[start - 1] * arr[i] * arr[end] + dfs(arr, start, i, dp) +
                dfs(arr, i + 1, end, dp);
    minimum = std::min(minimum, steps);
  }
  return dp[start][end] = minimum;
}

int mcm(std::vector<int> &arr) {
  std::vector<std::vector<int>> dp(arr.size(),
                                   std::vector<int>(arr.size(), -1));
  return dfs(arr, 1, arr.size() - 1, dp);
}
int mcmTab(std::vector<int> &arr) {
  int n = arr.size();

  // dp[start][end] initialized to 0.
  // This perfectly handles the base case: start == end requires 0 cost.
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

  // 1. Loop 'i' (start) backwards from the 2nd-to-last matrix down to 1
  for (int i = n - 1; i >= 1; i--) {

    // 2. Loop 'j' (end) forwards, starting strictly after 'i'
    for (int j = i + 1; j < n; j++) {

      int minimum = INT_MAX;

      // 3. Loop 'k' (the cut). It goes from 'i' up to 'j - 1'
      for (int k = i; k < j; k++) {

        // Exactly the same logic as your top-down!
        int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + // Left Partition
                    dp[k + 1][j];                             // Right Partition

        minimum = std::min(minimum, steps);
      }

      // Save the minimum cost for this specific (start to end) chunk
      dp[i][j] = minimum;
    }
  }

  // Return the cost of multiplying from the first matrix (1) to the last (n -
  // 1)
  return dp[1][n - 1];
}

int main() {
  std::vector<int> arr = {10, 20, 30, 40, 50};
  std::cout << mcmTab(arr) << "\n"; // Expected Output: 38000
  return 0;
}
