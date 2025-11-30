#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (mpp.find(complement) != mpp.end()) {
      return {i, mpp[complement]};
    }
    if (mpp.find(complement) == mpp.end()) {
      mpp[nums[i]] = i;
    }
  }
  return {};
}
