#include <unordered_map>
#include <vector>

using namespace std;

// Input: nums = [1, -1, 5, -2, 3], k = 3
// Output: 4
// Explanation: [1, -1, 5, -2] has sum 3 and length 4.

int longestSubArraySum(vector<int> &nums, int k) {
  int left = 0, result = 0, sum = 0;
  unordered_map<int, int> mpp;
  for (int right = 0; right < nums.size(); right++) {
    sum += nums[right];
    if (sum == k) {
      result = max(result, right + 1);
    }
    if (mpp.count(sum - k)) {
      result = max(result, right - mpp[sum - k]);
    }
    if (!mpp.count(sum - k)) {
      mpp[sum - k] = right;
    }
  }
  return result;
}
