#include <algorithm>
#include <unordered_map>
#include <vector>

int zeroOnes(std::vector<int> &nums) {
  int maxLen = 0, sum = 0;
  std::unordered_map<int, int> mpp;
  mpp[0] = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      sum += -1;
    } else {
      sum += nums[i];
    }

    if (mpp.find(sum) != mpp.end()) {
      maxLen = std::max(maxLen, i - mpp[sum]);
    } else {
      mpp[sum] = i;
    }
  }
  return maxLen;
}
