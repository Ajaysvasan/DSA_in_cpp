#include <vector>

int maxSubArray(std::vector<int> &nums) {
  int sum = nums[0];
  int maxSum = nums[0];
  for (int i = 0; i < nums.size(); i++) {
    sum = std::max(nums[i], sum + nums[i]);
    maxSum = std::max(maxSum, sum);
  }
  return maxSum;
}
