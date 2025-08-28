// [1,2,4,5]
// Return 3
// for i in range(0,len(nums)+1):
//      if(i+1 != nums[i])
//      return i+1
#include <iostream>
#include <vector>
class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int n = nums.size();
    int expectedTotal = (n + 1) * (n + 2) / 2;
    int actualTotal = 0;
    for (int num : nums) {
      actualTotal += num;
    }
    return expectedTotal - actualTotal;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  Solution s;
  std::cout << s.missingNumber(nums) << std::endl;
  return 0;
}
