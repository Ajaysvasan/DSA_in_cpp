#include <vector>
using namespace std;

// sum <= k varaint
int maxLength(vector<int> &nums, int k) {
  int left = 0, max_len = 0;
  long long sum = 0;
  for (int right = 0; right < nums.size(); right++) {
    sum += nums[right];
    while (sum <= k) {
      sum -= nums[left];
      left++;
    }
    max_len = max(max_len, right - left + 1);
  }
  return max_len;
}

// sum = k variant
int longestSubarrayWithSumK(vector<int> &nums, int k) {
  int left = 0, sum = 0, max_len = 0;
  for (int right = 1; right < nums.size(); right++) {
    sum += nums[right];
    while (sum < k) {
      sum -= nums[left];
    }
    if (sum == k) {
      max_len = max(max_len, right - left + 1);
    }
  }
  return max_len;
}
