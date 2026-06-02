#include <bits/stdc++.h>

int dfs(std::string &s1, std::string &s2, int idx_one, int idx_two,
        std::vector<std::vector<int>> &memo) {
  if (idx_one < 0)
    return idx_two + 1;
  if (idx_two < 0)
    return idx_one + 1;
  if (memo[idx_one][idx_two] != -1)
    return memo[idx_one][idx_two];
  if (s1[idx_one] == s2[idx_two]) {
    return dfs(s1, s2, idx_one - 1, idx_two - 1, memo);
  }
  int insert = 1 + dfs(s1, s2, idx_one, idx_two - 1, memo);
  int del = 1 + dfs(s1, s2, idx_one - 1, idx_two, memo);
  int replace = 1 + dfs(s1, s2, idx_one - 1, idx_two - 1, memo);
  return memo[idx_one][idx_two] = std::min(insert, std::min(del, replace));
}

int editDistance(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> memo(s1.size() + 1,
                                     std::vector<int>(s2.size() + 1, -1));
  return dfs(s1, s2, s1.size() - 1, s2.size() - 1, memo);
}

int editDistanceTab(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> dp(s1.size() + 1,
                                   std::vector<int>(s2.size() + 1, -1));
  for (int j = 0; j <= s2.size(); j++) {
    dp[0][j] = j;
  }
  for (int i = 0; i <= s1.size(); i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min(1 + dp[i][j - 1],
                            std::min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]));
      }
    }
  }
  return dp[s1.size()][s2.size()];
}

int editDistanceSo(std::string &s1, std::string &s2) {
  std::vector<int> prev(s2.size() + 1, 0);
  std::vector<int> curr(s2.size() + 1, 0);
  for (int j = 0; j <= s2.size(); j++) {
    prev[j] = j;
  }
  for (int i = 1; i <= s1.size(); i++) {
    curr[0] = i;
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        curr[j] = prev[j - 1];
      } else {
        curr[j] = 1 + std::min(prev[j], std::min(curr[j - 1], prev[j - 1]));
      }
    }
    prev = curr;
  }
  return prev[s2.size()];
}

int main(int argc, char *argv[]) {
  std::string s1 = "horse";
  std::string s2 = "ros";
  std::cout << editDistanceSo(s1, s2);
  return 0;
}
