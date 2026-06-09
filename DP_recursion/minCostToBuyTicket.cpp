#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dfs(vector<int> &days, vector<int> &costs, int idx, vector<int> &dp) {
    if (idx >= days.size())
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
    int i;
    int costOne = costs[0] + dfs(days, costs, idx + 1, dp);
    i = idx;
    while (i < days.size() && days[i] < days[idx] + 7) {
      i++;
    }
    int costTwo = costs[1] + dfs(days, costs, i, dp);
    i = idx;
    while (i < days.size() && days[i] < days[idx] + 30) {
      i++;
    }
    int costThree = costs[2] + dfs(days, costs, i, dp);
    return dp[idx] = min({costOne, costTwo, costThree});
  }

public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(days.size(), -1);
    return dfs(days, costs, 0, dp);
  }
};
