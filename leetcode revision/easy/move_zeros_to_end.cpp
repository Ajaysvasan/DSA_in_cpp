// Given an integer array nums, move all 0's to the end of it while maintaining
// the
//                                      relative order of the non -
//                                  zero elements.
//
//                                  Note that you must do this in -
//                                  place without making a copy of the array.
//
//                                  Example 1 :
//
//     Input : nums = [ 0, 1, 0, 3, 12 ] Output : [ 1, 3, 12, 0, 0 ] Example 2 :
//
//     Input : nums = [0] Output : [0]

#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums) {

  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] != 0) {
      std::swap(nums[i], nums[j]);
      i++;
    }
  }
}

int main() {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroes(nums);
  for (int num : nums) {
    std::cout << num;
  }
  return 0;
}
