#include <bits/stdc++.h>
#include <vector>

int dfs(std::string &s1, std::string &s2, int idx_one, int idx_two,
        std::vector<std::vector<int>> &dp) {
  if (idx_one < 0 || idx_two < 0)
    return 0;
  if (dp[idx_one][idx_two] != -1)
    return dp[idx_one][idx_two];
  if (s1[idx_one] == s2[idx_two]) {
    return dp[idx_one][idx_two] = 1 + dfs(s1, s2, idx_one - 1, idx_two - 1, dp);
  }
  return dp[idx_one][idx_two] = 0;
}

int longestCommonString(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> dp(s1.size(), std::vector<int>(s2.size(), -1));
  int max_len = INT_MIN;
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      int len = dfs(s1, s2, i, j, dp);

      max_len = std::max(max_len, len);
    }
  }
  return max_len;
}

int longestCommonStringTab(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> dp(s1.size() + 1,
                                   std::vector<int>(s2.size() + 1, 0));
  int max_len = 0;
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];

        max_len = std::max(max_len, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return max_len;
}

int main(int argc, char *argv[]) {
  std::string s1 = "abcde";
  std::string s2 = "abfce";
  std::cout << longestCommonStringTab(s1, s2);
  return 0;
}
