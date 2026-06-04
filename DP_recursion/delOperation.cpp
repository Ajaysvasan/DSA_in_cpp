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
    return memo[idx_one][idx_two] =
               0 + dfs(s1, s2, idx_one - 1, idx_two - 1, memo);
  }
  return memo[idx_one][idx_two] =
             std::min(1 + dfs(s1, s2, idx_one - 1, idx_two, memo),
                      1 + dfs(s1, s2, idx_one, idx_two - 1, memo));
}

int minDeleOperations(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> memo(s1.size() + 1,
                                     std::vector<int>(s2.size() + 1, -1));
  return dfs(s1, s2, s1.size() - 1, s2.size() - 1, memo);
}

int minDeleOperationsTab(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> dp(s1.size() + 1,
                                   std::vector<int>(s2.size() + 1, -1));
  for (int i = 0; i <= s1.size(); i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= s2.size(); j++) {
    dp[0][j] = j;
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
      }
    }
  }
  return dp[s1.size()][s2.size()];
}

int main(int argc, char *argv[]) {
  std::string s1 = "sea";
  std::string s2 = "eat";
  std::cout << minDeleOperationsTab(s1, s2);
  return 0;
}
