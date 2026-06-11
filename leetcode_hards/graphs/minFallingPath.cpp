#include <algorithm>
#include <vector>

class Solution {
  int dfs(std::vector<std::vector<int>> &matrix, int row, int col, int m, int n,
          std::vector<std::vector<int>> &dp) {
    if (col < 0 || col >= n) {
      return 1e8;
    }
    if (row == m) {
      return 0;
    }
    if (dp[row][col] != 1e9)
      return dp[row][col];
    // next element position (row + 1 ,col) , (row + 1, col -1) , (row + 1 , col
    // +1)
    int diagonalLeft = dfs(matrix, row + 1, col + 1, m, n, dp);
    int diagonalRight = dfs(matrix, row + 1, col - 1, m, n, dp);
    int down = dfs(matrix, row + 1, col, m, n, dp);
    return dp[row][col] =
               matrix[row][col] + std::min({diagonalLeft, diagonalRight, down});
  }

public:
  int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int minValue = 1e9;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1e9));
    for (int j = 0; j < n; j++) {
      int current_value = dfs(matrix, 0, j, m, n, dp);
      minValue = std::min(minValue, current_value);
    }
    return minValue;
  }
};
