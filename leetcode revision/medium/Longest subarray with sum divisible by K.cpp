#include <unordered_map>
#include <vector>

int longestSubarrayDivisibleByK(std::vector<int> &nums, int k) {
  int maxLen = 0, sum = 0;
  std::unordered_map<int, int> mpp;
  mpp[0] = -1;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int rem = sum % k;
    if (rem < 0)
      rem += k;
    if (mpp.find(rem) != mpp.end()) {
      maxLen = std::max(maxLen, i - mpp[rem] + 1);
    }
    if (mpp.find(rem) == mpp.end()) {
      mpp[rem] = i;
    }
  }
  return maxLen;
}
