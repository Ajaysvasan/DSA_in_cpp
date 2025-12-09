#include <deque>
#include <iostream>
#include <vector>

std::vector<int> slidingWindowMaximum(std::vector<int> &nums, int k) {
  std::vector<int> result;
  std::deque<int> dq;
  for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && dq.front() <= i - k) {
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
  std::vector<int> nums = {1, 3, -1, 5, 3, 6, 7};
  int k = 3;
  std::vector<int> result = slidingWindowMaximum(nums, k);
  for (int num : result) {
    std::cout << num << " ";
  }
}
