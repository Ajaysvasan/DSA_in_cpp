#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
  int dfs(std::vector<int> &arr, int start, int end,
          std::vector<std::vector<int>> &dp) {
    if (end - start <= 1) {
      return 0;
    }
    if (dp[start][end] != -1)
      return dp[start][end];
    int max_cost = INT_MIN;
    for (int k = start + 1; k < end; k++) {
      int cost = arr[start] * arr[k] * arr[end] + dfs(arr, start, k, dp) +
                 dfs(arr, k, end, dp);
      max_cost = std::max(max_cost, cost);
    }
    return dp[start][end] = max_cost;
  }

  int maxCoinsMemo(std::vector<int> &nums) {
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    std::vector<std::vector<int>> dp(nums.size(),
                                     std::vector<int>(nums.size(), -1));
    return dfs(nums, 0, nums.size() - 1, dp);
  }

public:
  int maxCoins(std::vector<int> &nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    std::vector<std::vector<int>> dp(nums.size() + 2,
                                     std::vector<int>(nums.size() + 2, 0));
    for (int i = n; i >= 0; i--) {
      for (int j = i + 1; j < nums.size(); j++) {
        int max_cost = 0;
        if (j - i > 1) {
          for (int k = i + 1; k < j; k++) {
            int curr_cost = nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j];
            max_cost = std::max(max_cost, curr_cost);
          }
        }
        dp[i][j] = max_cost;
      }
    }
    return dp[0][n + 1];
  }
};
int main(int argc, char *argv[]) {
  std::vector<int> balloons = {3, 1, 5, 8};
  Solution sol;
  std::cout << sol.maxCoins(balloons);
  return 0;
}
