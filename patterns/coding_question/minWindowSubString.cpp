#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {

    unordered_map<char, int> need, have;
    for (char c : t)
      need[c]++;

    int required = need.size();
    int formed = 0;

    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
      char c = s[right];
      have[c]++;

      if (need.count(c) && have[c] == need[c]) {
        formed++;
      }

      while (formed == required) {
        if (right - left + 1 < minLen) {
          minLen = right - left + 1;
          start = left;
        }

        char d = s[left];
        have[d]--;
        if (need.count(d) && have[d] < need[d]) {
          formed--;
        }
        left++;
      }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};
int main(int argc, char *argv[]) {
  std::string str, target;
  std::cin >> str >> target;
  Solution sol;
  cout << sol.minWindow(str, target);
  return 0;
}
