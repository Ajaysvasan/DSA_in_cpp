#include <unordered_map>
#include <vector>

int niceArray(std::vector<int> &nums, int k) {
  int prefix = 0, ans = 0;
  std::unordered_map<int, int> mpp;
  mpp[0] = 1;
  for (int num : nums) {
    prefix += (num % 2);
    if (mpp.find(prefix - k) != mpp.end()) {
      ans += mpp[prefix - k];
    }
    mpp[prefix]++;
  }
  return ans;
}
