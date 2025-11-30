#include <algorithm>
#include <utility>
#include <vector>

void nextPermutation(std::vector<int> &nums) {
  int breaking_point = -1;
  for (int i = nums.size() - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      breaking_point = i;
      break;
    }
  }
  if (breaking_point == -1) {
    std::reverse(nums.begin(), nums.end());
    return;
  }
  for (int i = nums.size() - 1; i >= breaking_point; i--) {
    if (nums[i] > nums[breaking_point]) {
      std::swap(nums[i], nums[breaking_point]);
      break;
    }
  }
  std::reverse(nums.begin() + breaking_point + 1, nums.end());
}
