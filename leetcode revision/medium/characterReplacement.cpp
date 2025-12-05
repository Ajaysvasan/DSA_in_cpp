#include <string>
using namespace std;
int characterReplacement(string s, int k) {
  int lastSeen[26];
  fill(begin(lastSeen), end(lastSeen), 0);
  int left = 0, maxLen = 0, maxFreq = 0;
  for (int right = 0; right < s.size(); right++) {
    lastSeen[s[right] - 'A']++;
    maxFreq = max(maxFreq, lastSeen[s[right] - 'A']);
    while ((right - left + 1) - maxFreq > k) {
      lastSeen[s[left] - 'A']--;
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
  }
  return maxLen;
}
