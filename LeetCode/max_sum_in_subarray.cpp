#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &nums, int k) {
  int window_size = 0, max_sum = 0;
  for (int i = 0; i < k; i++) {
    window_size += nums[i];
  }
  for (int right = k; right < nums.size(); right++) {
    window_size += nums[right];
    window_size -= nums[right - k];
    max_sum = max(max_sum, window_size);
  }
  return max_sum;
}
