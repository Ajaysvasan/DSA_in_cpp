#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int max_len = 0;
    std::unordered_set<char> char_set;
    int left = 0;
    for (int right = 0; right < s.length(); right++) {
      while (char_set.find(s[right]) != char_set.end()) {
        char_set.erase(s[right]);
        left++;
      }
      char_set.insert(s[right]);
      max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
  }
};

int main() {
  std::string str = "abcabcbb";
  Solution s;
  int res = s.lengthOfLongestSubstring(str);
  int e_out = 3;
  std::cout << (res == e_out) ? true : false;
}
