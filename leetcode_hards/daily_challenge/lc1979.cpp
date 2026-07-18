#include <climits>
#include <numeric>
#include <vector>

class Solution {
public:
  int findGCD(std::vector<int> &nums) {
    int minElement = INT_MAX;
    int maxElement = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < minElement) {
        minElement = nums[i];
      }
      if (nums[i] > maxElement) {
        maxElement = nums[i];
      }
    }
    return std::gcd(maxElement, minElement);
  }
};
