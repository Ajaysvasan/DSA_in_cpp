#include <iostream>
#include <vector>

class Solution {
public:
  int subArraysWithKDistinct(std::vector<int> &nums) {
    int count = 0;
    return count;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  Solution s;
  int res = s.subArraysWithKDistinct(nums);
  std::cout << res;
  return 0;
}
