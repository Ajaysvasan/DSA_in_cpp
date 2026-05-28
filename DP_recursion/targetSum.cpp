#include <iostream>
#include <vector>

int findTargetSumWays(std::vector<int> &nums, int target) {
  int sum = 0;
  for (int value : nums) {
    sum += value;
  }
  if (sum < target || (sum + target) % 2 == 1) {
    return 0;
  }
  int newTarget = (sum + target) / 2;
  std::vector<std::vector<int>> dp(nums.size() + 1,
                                   std::vector<int>(newTarget + 1, 0));
  for (int i = 0; i <= nums.size(); i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= nums.size(); i++) {
    for (int j = 1; j <= newTarget; j++) {
      if (nums[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[nums.size()][newTarget];
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  std::cout << findTargetSumWays(nums, target) << std::endl;
  return 0;
}
