#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int dfs(std::string &s1, std::string &s2, int index_one, int index_two,
        std::vector<std::vector<int>> &memo) {
  if (index_one < 0 || index_two < 0) {
    return 0;
  }
  if (memo[index_one][index_two] != -1)
    return memo[index_one][index_two];
  if (s1[index_one] == s2[index_two]) {
    return memo[index_one][index_two] =
               1 + dfs(s1, s2, index_one - 1, index_two - 1, memo);
  }
  return memo[index_one][index_two] =
             0 + std::max(dfs(s1, s2, index_one - 1, index_two, memo),
                          dfs(s1, s2, index_one, index_two - 1, memo));
}

int lcs(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> memo(s1.size(),
                                     std::vector<int>(s2.size(), -1));
  return dfs(s1, s2, s1.size() - 1, s2.size() - 1, memo);
}

int lcsTab(std::string &s1, std::string &s2) {
  std::vector<std::vector<int>> dp(s1.size() + 1,
                                   std::vector<int>(s2.size() + 1, 0));
  for (int i = 0; i <= s1.size(); i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= s2.size(); j++) {
    dp[0][j] = 0;
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[s1.size()][s2.size()];
}

int main(int argc, char *argv[]) {
  std::string s1 = "abcde";
  std::string s2 = "ace";
  std::cout << lcsTab(s1, s2) << std::endl;
  return 0;
}
