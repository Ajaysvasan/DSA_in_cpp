#include <bits/stdc++.h>

int lcs(std::string &s1) {
  int n = s1.size();
  std::string s2 = s1;
  std::reverse(s2.begin(), s2.end());
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][n];
}

int minInstPal(std::string &s) {
  int longestPrimeSeq = lcs(s);
  return s.size() - longestPrimeSeq;
}

int main(int argc, char *argv[]) {
  std::string s = "mbadm";
  std::cout << minInstPal(s);
  return 0;
}
