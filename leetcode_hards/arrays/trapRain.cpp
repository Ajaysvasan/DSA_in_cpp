#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int left = 0, right = height.size() - 1, maxLeft = 0, maxRight = 0;
    int water;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= maxLeft) {
          maxLeft = height[left];
        } else {
          water += maxLeft - height[left];
        }
        left++;
      } else {
        if (height[right] >= maxRight) {
          maxRight = height[right];
        } else {
          water += maxRight - height[right];
        }
        right--;
      }
    }
    return water;
  }
};
