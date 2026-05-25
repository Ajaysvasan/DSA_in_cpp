#include <algorithm>
#include <iostream>
#include <vector>
int dfs(std::vector<int> &nums, int idx) {
  if (idx >= nums.size()) {
    return 0;
  }

  int costOneStep = dfs(nums, idx + 1);
  int costTwoSteps = dfs(nums, idx + 2);

  return nums[idx] + std::min(costOneStep, costTwoSteps);
}
int dfs(std::vector<int> &nums, int idx, std::vector<int> &memo) {
  if (idx >= nums.size()) {
    return 0;
  }
  if (memo[idx] != -1)
    return memo[idx];

  int costOneStep = dfs(nums, idx + 1);
  int costTwoSteps = dfs(nums, idx + 2);

  return memo[idx] = nums[idx] + std::min(costOneStep, costTwoSteps);
}

int minCost(std::vector<int> &nums) {
  std::vector<int> memo(nums.size() + 1, -1);
  return std::min(dfs(nums, 0, memo), dfs(nums, 1, memo));
}

int minCostTab(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    int countOne = dp[i - 1] + nums[i - 1];
    int countTwo = dp[i - 2] + nums[i - 2];
    dp[i] = std::min(countOne, countTwo);
  }
  return dp[n];
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {10, 15, 30};
  std::cout << minCostTab(nums);
  return 0;
}
