#include <string>
using namespace std;
// Optimal way one

int longestSubStringLengthVariantOne(string s) {
  int lastIndex[26];
  fill(begin(lastIndex), end(lastIndex), -1);
  int left = 0, maxLen = 0;
  for (int right = 0; right < s.size(); right++) {
    if (lastIndex[s[right] - 'a'] >= left) {
      left = lastIndex[s[right] - 'a'] + 1;
    }
    lastIndex[s[right] - 'a'] = right;
    maxLen = max(maxLen, right - left + 1);
  }
  return maxLen;
}

// Optimal way two
int longestSubStringLengthVariantTwo(string s) {
  int mask = 0; // 26-bit window (only lowercases)
  int left = 0, maxLen = 0;

  for (int right = 0; right < s.size(); right++) {
    int bit = 1 << (s[right] - 'a');

    // If this character already exists in window
    while (mask & bit) {
      // Remove s[left] from the mask
      int removeBit = 1 << (s[left] - 'a');
      mask ^= removeBit;
      left++;
    }

    // Add current character
    mask |= bit;

    // Update max length
    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}
