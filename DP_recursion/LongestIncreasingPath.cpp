#include <bits/stdc++.h>

int dfs(std::vector<std::vector<int>> &matrix, int row, int col,
        std::vector<std::vector<int>> &dp, int prev) {
  if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() ||
      matrix[row][col] <= prev) {
    return 0;
  }
  if (dp[row][col] != -1)
    return dp[row][col];
  int up = dfs(matrix, row - 1, col, dp, matrix[row][col]);
  int down = dfs(matrix, row + 1, col, dp, matrix[row][col]);

  int left = dfs(matrix, row, col - 1, dp, matrix[row][col]);
  int right = dfs(matrix, row, col + 1, dp, matrix[row][col]);
  return dp[row][col] = 1 + std::max({up, right, left, down});
}

int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
  std::vector<std::vector<int>> dp(matrix.size(),
                                   std::vector<int>(matrix[0].size(), -1));
  int max_path = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      max_path = std::max(max_path, dfs(matrix, i, j, dp, -1));
    }
  }
  return max_path;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  std::cout << longestIncreasingPath(matrix);
  return 0;
}
