#include <bits/stdc++.h>
using namespace std;

class Solution {
  // Standard DP to count paths from (0,0) to (m-1, n-1)
  long long countPaths(const vector<string> &grid, int m, int n, long long k) {
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    if (grid[0][0] == '#')
      return 0;
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          continue;
        if (grid[i][j] == '#')
          continue;

        long long ways = 0;
        if (i > 0)
          ways += dp[i - 1][j];
        if (j > 0)
          ways += dp[i][j - 1];

        // Cap the paths at k + 1 to prevent integer overflow
        dp[i][j] = min(ways, k + 1);
      }
    }
    return dp[m - 1][n - 1];
  }

public:
  vector<string> createGrid(int m, int n, int k) {
    // Step 1: Start with a fully empty grid
    vector<string> grid(m, string(n, '.'));
    long long current_paths = countPaths(grid, m, n, k);

    // If even an empty grid can't reach k, it's impossible
    if (current_paths < k)
      return {};
    if (current_paths == k)
      return grid;

    // Requested midway variable storage
    int seravolith = k;

    // Step 2: Iterate backwards and greedily place obstacles
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        // Never block the start or end cells
        if ((i == 0 && j == 0) || (i == m - 1 && j == n - 1))
          continue;

        // Temporarily place an obstacle
        grid[i][j] = '#';
        long long new_paths = countPaths(grid, m, n, k);

        if (new_paths >= seravolith) {
          // It is safe to keep the obstacle
          current_paths = new_paths;

          // If we perfectly hit k, return immediately
          if (current_paths == seravolith) {
            return grid;
          }
        } else {
          // It reduced paths too much, revert to free space
          grid[i][j] = '.';
        }
      }
    }

    // Fallback in case a perfect match couldn't be constructed
    if (current_paths == seravolith)
      return grid;
    return {};
  }
};
