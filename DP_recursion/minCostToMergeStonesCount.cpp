#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int dfs(std::vector<int> &arr, int start, int end,
        std::vector<std::vector<int>> &dp, std::vector<int> &prefix_sum) {

  if (start == end)
    return 0;

  if (dp[start][end] != -1)
    return dp[start][end];

  int min_cost = INT_MAX;

  for (int k = start; k < end; k++) {

    int cost = dfs(arr, start, k, dp, prefix_sum) +
               dfs(arr, k + 1, end, dp, prefix_sum);

    min_cost = std::min(cost, min_cost);
  }

  int current_merge_cost = prefix_sum[end + 1] - prefix_sum[start];

  return dp[start][end] = min_cost + current_merge_cost;
}

int mergeAdjMemo(std::vector<int> &arr) {
  int n = arr.size();
  if (n == 0)
    return 0;
  std::vector<int> prefix_sum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefix_sum[i + 1] = prefix_sum[i] + arr[i];
  }

  std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
  return dfs(arr, 0, n - 1, dp, prefix_sum);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 3, 2, 6};
  std::cout << "Minimum Cost to Merge: " << mergeAdjMemo(arr)
            << "\n"; // Expected: 29
  return 0;
}
