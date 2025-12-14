#include <deque>
#include <iostream>
#include <vector>

// Input:
// nums = [1,3,-1,-3,5,3,6,7]
// k = 3

// Output:
// [3,3,5,5,6,7]
// Explanation
// [1, 3, -1] → 3
// [3, -1, -3] → 3
// [-1, -3, 5] → 5
// [-3, 5, 3] → 5
// [5, 3, 6] → 6
// [3, 6, 7] → 7

std::vector<int> maximumSlidingWindow(std::vector<int> &nums, int k) {
  std::deque<int> dq;
  std::vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    while (!dq.empty() && nums[i] >= nums[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      result.push_back(nums[dq.front()]);
    }
  }
  return result;
}
int main() {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<int> result = maximumSlidingWindow(nums, 3);
  for (int num : result) {
    std::cout << num << " ";
  }
}
