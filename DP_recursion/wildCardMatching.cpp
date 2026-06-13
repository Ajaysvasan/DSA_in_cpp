#include <string>
#include <vector>
using namespace std;

class Solution {
  bool dfs(string s, string p, int idx_one, int idx_two,
           vector<vector<int>> &dp) {
    if (idx_one < 0 && idx_two < 0)
      return true;
    if (idx_one >= 0 && idx_two < 0)
      return false;
    if (idx_one < 0 && idx_two >= 0) {
      for (int i = 0; i <= idx_two; i++) {
        if (p[i] != '*')
          return false;
      }
      return true;
    }
    if (dp[idx_one][idx_two] != -1)
      return dp[idx_one][idx_two];
    if (s[idx_one] == p[idx_two] || p[idx_two] == '?') {
      return dp[idx_one][idx_two] = dfs(s, p, idx_one - 1, idx_two - 1, dp);
    }
    if (p[idx_two] == '*') {
      return dp[idx_one][idx_two] = dfs(s, p, idx_one - 1, idx_two, dp) ||
                                    dfs(s, p, idx_one, idx_two - 1, dp);
    }
    return dp[idx_one][idx_two] = false;
  }
  bool isMatchMemo(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return dfs(s, p, m - 1, n - 1, dp);
  }

public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= n; j++) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 1]; // True if the previous was also true
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else {
          dp[i][j] = false;
        }
      }
    }

    return dp[m][n];
  }
};
