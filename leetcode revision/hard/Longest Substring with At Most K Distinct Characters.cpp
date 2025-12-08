#include <string>
#include <unordered_map>

int maxSubString(std::string s, int k) {
  int l = 0, result = 0;
  std::unordered_map<char, int> mpp;

  for (int r = 0; r < s.size(); r++) {
    mpp[s[r]]++;

    while (mpp.size() > k) {
      mpp[s[l]]--;
      if (mpp[s[l]] == 0) {
        mpp.erase(s[l]);
      }
      l++;
    }

    result = std::max(result, r - l + 1);
  }

  return result;
}
