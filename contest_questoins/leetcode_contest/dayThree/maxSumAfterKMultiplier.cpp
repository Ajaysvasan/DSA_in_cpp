#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  long long maxSubarraySum(std::vector<int> &nums, int k) {
    long long const INF = -1e18;

    long long dp0 = INF;
    long long dp1 = INF;
    long long dp2 = INF;

    long long maxSum = INF;

    for (int i = 0; i < nums.size(); i++) {
      long long val = nums[i];
      long long modVal = (long long)nums[i] * k;

      long long next_dp0 = std::max(val, dp0 + val);

      long long next_dp1 = std::max({modVal, dp0 + modVal, dp1 + modVal});

      long long next_dp2 = std::max({dp1 + val, dp2 + val});

      dp0 = next_dp0;
      dp1 = next_dp1;
      dp2 = next_dp2;

      maxSum = std::max({maxSum, dp0, dp1, dp2});
    }

    return maxSum;
  }
};
int main(int argc, char *argv[]) {
  std::vector<int> nums = {1, -2, 3, 4, -5};
  Solution sol;
  std::cout << sol.maxSubarraySum(nums, 2);
  return 0;
}
