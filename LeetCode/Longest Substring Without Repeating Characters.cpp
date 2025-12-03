#include <string>
#include <unordered_set>
using namespace std;

int longestSubStringLength(string &s) {
  int left = 0, max_length = 1;
  unordered_set<char> window;
  for (int right = 1; right < s.size(); right++) {
    while (window.find(s[right]) != window.end()) {
      window.erase(s[left]);
      left++;
    }
    window.insert(s[right]);
    max_length = max(max_length, right - left + 1);
  }
  return max_length;
}
