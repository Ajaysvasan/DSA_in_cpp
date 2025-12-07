#include <unordered_map>
#include <vector>

int longestSubArrayWithSumZero(std::vector<int> &nums) {
  std::unordered_map<int, int> mpp;
  int count = 0, sum = 0;
  for (int num : nums) {
    sum += num;
    if (sum == 0) {
      count++;
    }
    if (mpp.find(sum) != mpp.end()) {
      count += mpp[sum];
    }
    mpp[sum]++;
  }
  return count;
}
