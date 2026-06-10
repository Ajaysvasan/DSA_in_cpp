#include <vector>

class Solution {
  int MOD = 1e9 + 7;
  int dfs(std::vector<std::vector<int>> &grid, int k, int row, int col, int sum,
          std::vector<std::vector<std::vector<int>>> &dp) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
      return 0;
    }
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
      return ((sum + grid[row][col]) % k == 0) ? 1 : 0;
    }
    if (dp[row][col][sum] != -1)
      return dp[row][col][sum];
    int next_mod = (sum + grid[row][col]) % k;
    int down = dfs(grid, k, row + 1, col, next_mod, dp);
    int right = dfs(grid, k, row, col + 1, next_mod, dp);
    return dp[row][col][sum] = (right + down) % MOD;
  }

public:
  int numberOfPaths(std::vector<std::vector<int>> &grid, int k) {
    std::vector<std::vector<std::vector<int>>> dp(
        grid.size(),
        std::vector<std::vector<int>>(grid[0].size(), std::vector<int>(k, -1)));
    return dfs(grid, k, 0, 0, 0, dp);
  }
};
