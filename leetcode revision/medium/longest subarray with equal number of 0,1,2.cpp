#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

int longestEqual012Subarray(std::vector<int> &nums) {
  int count0 = 0, count1 = 0, count2 = 0;
  int maxLen = 0;

  // Hashmap stores pair(diff10,diff21) → first index
  std::unordered_map<std::string, int> mpp;
  mpp["0#0"] = -1; // initial pair

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0)
      count0++;
    else if (nums[i] == 1)
      count1++;
    else
      count2++;

    int diff10 = count1 - count0;
    int diff21 = count2 - count1;

    std::string key = std::to_string(diff10) + "#" + std::to_string(diff21);

    if (mpp.find(key) != mpp.end()) {
      maxLen = std::max(maxLen, i - mpp[key]);
    } else {
      mpp[key] = i;
    }
  }

  return maxLen;
}
