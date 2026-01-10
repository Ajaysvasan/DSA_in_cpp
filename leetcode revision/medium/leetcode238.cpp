#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> res(nums.size(), 1);
    int left = 1;
    for (int i = 0; i < nums.size(); i++) {
      res[i] *= left;
      left *= nums[i];
    }
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] *= right;
      right *= nums[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 4};
  std::cout << "The output for the code is: " << "\n";
  for (int num : s.productExceptSelf(nums)) {
    std::cout << num << " ";
  }
  return 0;
}
