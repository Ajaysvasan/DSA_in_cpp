#include <unordered_map>
#include <vector>
using namespace std;

// Input: nums = [1,2,1,2,3], k = 2
// Output: 4
// Explanation: The longest subarray is [1,2,1,2]
//
int longestSubArray(vector<int> &nums, int k) {
  int left = 0, maxLen = 0;
  unordered_map<int, int> freq;
  for (int right = 0; right < nums.size(); right++) {
    freq[nums[right]]++;
    while (freq.size() > k) {
      freq[nums[left]]--;
      if (freq[nums[left]] == 0) {
        freq.erase(nums[left]);
      }
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}
