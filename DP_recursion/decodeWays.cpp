#include <bits/stdc++.h>

class Solution {
public:
  int dfs(std::string &s, int index, std::vector<int> &dp) {
    if (index == s.size()) {
      return 1;
    }
    if (s[index] == '0') {
      return 0;
    }
    if (dp[index] != -1) {
      return dp[index];
    }
    int count = dfs(s, index + 1, dp);
    if (index + 1 < s.size() &&
        (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
      count += dfs(s, index + 2, dp);
    }
    return dp[index] = count;
  }
  int numDecodings(std::string s) {
    std::vector<int> dp(s.size(), -1);
    return dfs(s, 0, dp);
  }
};

int main(int argc, char *argv[]) {
  std::string s = "226";
  Solution sol;
  std::cout << sol.numDecodings(s);
  return 0;
}
