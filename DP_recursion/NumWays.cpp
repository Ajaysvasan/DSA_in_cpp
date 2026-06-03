#include <bits/stdc++.h>
#include <vector>

int dfs(std::string &s, std::string &t, int idx_one, int idx_two,
        std::vector<std::vector<int>> &dp) {
  if (idx_two == t.size())
    return 1;
  if (idx_one == s.size())
    return 0;
  if (dp[idx_one][idx_two] != -1)
    return dp[idx_one][idx_two];
  int count = 0;
  if (s[idx_one] == t[idx_two]) {
    count += dfs(s, t, idx_one + 1, idx_two + 1, dp);
  }
  count += dfs(s, t, idx_one + 1, idx_two, dp);
  return dp[idx_one][idx_two] = count;
}

int numsWays(std::string &s, std::string &t) {
  std::vector<std::vector<int>> dp(s.size() + 1,
                                   std::vector<int>(t.size() + 1, -1));
  return dfs(s, t, 0, 0, dp);
}

int numsWaysTab(std::string &s, std::string &t) {
  std::vector<std::vector<int>> dp(s.size() + 1,
                                   std::vector<int>(t.size() + 1, 0));
  for (int i = 0; i <= s.size(); i++) {
    dp[i][t.size()] = 1;
  }

  for (int i = s.size() - 1; i >= 0; i--) {
    for (int j = t.size() - 1; j >= 0; j--) {
      dp[i][j] += dp[i + 1][j];
      if (s[i] == t[j]) {
        dp[i][j] += dp[i + 1][j + 1];
      }
    }
  }
  return dp[0][0];
}

int main(int argc, char *argv[]) {
  std::string s = "baggbag";
  std::string t = "bag";
  std::cout << numsWaysTab(s, t) << std::endl;
  return 0;
}
