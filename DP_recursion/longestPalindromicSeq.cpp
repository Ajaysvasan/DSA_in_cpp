#include <bits/stdc++.h>
#include <vector>

int longestPalindromicSequence(std::string &s) {
  int n = s.size();
  std::string temp = s;
  std::reverse(temp.begin(), temp.end());
  std::vector<std::vector<int>> dp(s.size() + 1,
                                   std::vector<int>(s.size() + 1, -1));
  for (int i = 0; i <= s.size(); i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= s.size(); j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == temp[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else if (s[i - 1] != temp[j - 1]) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][n];
}

int main(int argc, char *argv[]) {
  std::string s = "cbbd";
  std::cout << longestPalindromicSequence(s);
  return 0;
}
