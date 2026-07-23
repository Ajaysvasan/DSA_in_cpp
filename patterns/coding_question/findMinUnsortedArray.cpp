#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> nums = {10, 15, 20, 30, 25, 40, 35, 45, 50, 60};
  int n = nums.size();

  if (n < 2)
    return 0;

  // 1. Find the first element out of order from the left
  int left = 0;
  while (left < n - 1 && nums[left] <= nums[left + 1]) {
    left++;
  }

  // If left reached the end, the array is already perfectly sorted
  if (left == n - 1) {
    for (int num : nums)
      std::cout << num << " ";
    return 0;
  }

  // 2. Find the first element out of order from the right
  int right = n - 1;
  while (right > 0 && nums[right] >= nums[right - 1]) {
    right--;
  }

  // 3. Find the min and max within the unsorted middle subarray
  int subarray_min = nums[left], subarray_max = nums[left];
  for (int i = left; i <= right; i++) {
    subarray_min = std::min(subarray_min, nums[i]);
    subarray_max = std::max(subarray_max, nums[i]);
  }

  // 4. Expand the boundaries if middle elements belong further out
  while (left > 0 && nums[left - 1] > subarray_min) {
    left--;
  }
  while (right < n - 1 && nums[right + 1] < subarray_max) {
    right++;
  }

  // 5. Sort the correctly identified subarray
  // Note the +1 because the end iterator is exclusive
  std::sort(nums.begin() + left, nums.begin() + right + 1);

  // Print result
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}
