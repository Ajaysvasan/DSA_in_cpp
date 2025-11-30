#include <vector>
void sortZeroOneTwo(std::vector<int> &nums) {
  int left = 0, mid = 0, high = nums.size() - 1;
  while (mid <= high) {
    if (nums[mid] == 0) {
      std::swap(nums[left], nums[mid]);
      left++;
      mid++;
    } else if (nums[mid] == 1) {
      mid++;
    } else {
      std::swap(nums[mid], nums[high]);
      high--;
    }
  }
}
