#include <string>
#include <unordered_map>
using namespace std;

int longestSubstringWithKDistinct(string s, int k) {
  int left = 0, maxLen = 0;
  unordered_map<char, int> mpp;
  for (int right = 0; right < s.size(); right++) {
    mpp[s[right]]++;
    while (mpp.size() > k) {
      mpp[s[left]]--;
      if (mpp[s[left]] == 0) {
        mpp.erase(s[left]);
      }
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
  }
  return maxLen;
}
