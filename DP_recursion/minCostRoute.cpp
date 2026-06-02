#include <bits/stdc++.h>

int dfs(std::vector<std::vector<int>> &grid, int row, int col,
        std::vector<std::vector<int>> &dp) {
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
    return INT_MAX;
  }
  if (row == grid.size() - 1 && col == grid[0].size() - 1) {
    return grid[row][col];
  }
  if (dp[row][col] != -1)
    return dp[row][col];
  int right = dfs(grid, row, col + 1, dp);
  int down = dfs(grid, row + 1, col, dp);
  return dp[row][col] = grid[row][col] + std::min(right, down);
}

int minCostRoute(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<int>> dp(grid.size(),
                                   std::vector<int>(grid[0].size(), -1));
  return dfs(grid, 0, 0, dp);
}

int minCostRouteTab(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<int>> dp(grid.size(),
                                   std::vector<int>(grid[0].size(), 0));
  int m = grid.size(), n = grid[0].size();
  dp[m - 1][n - 1] = grid[m - 1][n - 1];
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (i == m - 1 && j == n - 1)
        continue;
      int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
      int left = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;
      dp[i][j] = grid[i][j] + std::min(right, left);
    }
  }
  return dp[0][0];
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  std::cout << minCostRouteTab(grid);
  return 0;
}
