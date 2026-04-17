#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int maxFreq(string s, int k) {
    int ans = 1;
    int tCount = 0, fCount = 0;
    int left = 0;
    for (int right = 0; right < s.length(); right++) {
      if (s[right] == 'T') {
        tCount++;
      } else {
        fCount++;
      }
      while ((right - left + 1) - max(tCount, fCount) > k) {
        if (s[left] == 'T')
          tCount--;
        else
          fCount--;
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

int main() {
  string s = "TFTFTFTF";
  int k = 1;
  Solution S;
  cout << S.maxFreq(s, k);
  return 0;
}
