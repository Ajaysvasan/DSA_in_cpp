#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int maxOne = INT_MIN, maxTwo = INT_MIN;
    for (int num : nums) {
      if (maxOne < num) {
        maxTwo = maxOne;
        maxOne = num;
      } else if (num > maxTwo) {
        maxTwo = num;
      }
    }
    return (maxOne - 1) * (maxTwo - 1);
  }
};
