#include <vector>

// variation one
bool BinarySearchVariationOne(std::vector<std::vector<int>> &nums, int target) {
  int low = 0, high = (nums.size() * nums[0].size()) - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int row = mid / nums[0].size();
    int col = mid % nums[0].size();
    if (nums[row][col] == target) {
      return true;
    } else if (nums[row][col] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}

// variation two
bool binarySearch(std::vector<int> nums, int target) {
  int low = 0, high = nums.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}
bool BinarySearchVariationTwo(std::vector<std::vector<int>> &nums, int target) {
  int row = nums.size();
  int col = nums[0].size();
  for (int i = 0; i < row; i++) {
    if (nums[i][0] <= target && nums[i][col - 1] >= target) {
      if (binarySearch(nums[i], target)) {
        return true;
      }
    }
  }
  return false;
}
