#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
  int left = 0, right = height.size() - 1;
  int result = 0;
  while (left < right) {
    int curr_height = min(height[left], height[right]);
    int curr_width = right - left;
    result = max(result, curr_height * curr_width);
    if (height[left] <= height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return result;
}
