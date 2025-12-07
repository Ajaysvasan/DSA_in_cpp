#include <vector>

int trap(std::vector<int> &height) {
  int left = 0, right = height.size() - 1, maxRight = 0, maxLeft = 0;
  int water = 0;
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
    }
  }
  return water;
}
