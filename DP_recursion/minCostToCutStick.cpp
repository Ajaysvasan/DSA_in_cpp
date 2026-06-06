#include <bits/stdc++.h>
class Solution {
  int dfs(std::vector<int> &cuts, int start, int end,
          std::vector<std::vector<int>> &dp) {
    if (end - start <= 1) {
      return 0;
    }
    if (dp[start][end] != -1)
      return dp[start][end];
    int min_cost = INT_MAX;
    for (int k = start + 1; k < end; k++) {
      int curr_cost = dfs(cuts, start, k, dp) + dfs(cuts, k, end, dp) +
                      (cuts[end] - cuts[start]);
      min_cost = std::min(curr_cost, min_cost);
    }
    return dp[start][end] = min_cost;
  }

  int minCostMemo(int n, std::vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    std::sort(cuts.begin(), cuts.end());
    std::vector<std::vector<int>> dp(cuts.size(),
                                     std::vector<int>(cuts.size(), -1));
    return dfs(cuts, 0, cuts.size() - 1, dp);
  }

public:
  int minCost(int n, std::vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    std::sort(cuts.begin(), cuts.end());
    std::vector<std::vector<int>> dp(cuts.size(),
                                     std::vector<int>(cuts.size(), 0));
    for (int i = cuts.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < cuts.size(); j++) {
        if (j - i > 1) {
          int min_cost = INT_MAX;
          for (int k = i + 1; k < j; k++) {
            int curr_cost = dp[i][k] + dp[k][j] + cuts[j] - cuts[i];
            min_cost = std::min(min_cost, curr_cost);
          }
          dp[i][j] = min_cost;
        }
      }
    }
    return dp[0][cuts.size() - 1];
  }
};
int main(int argc, char *argv[]) {
  int n = 7;
  std::vector<int> cuts = {1, 3, 4, 5};
  Solution sol;
  std::cout << sol.minCost(n, cuts);
  return 0;
}
