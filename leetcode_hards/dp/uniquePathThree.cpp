#include <vector>

class Solution {
  int dfs(std::vector<std::vector<int>> &grid, int empty_count, int m, int n,
          int row, int col) {
    if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == -1) {
      return 0;
    }
    if (grid[row][col] == 2) {
      return empty_count == 0 ? 1 : 0;
    }

    grid[row][col] = -1;
    int up = dfs(grid, empty_count - 1, m, n, row - 1, col);
    int down = dfs(grid, empty_count - 1, m, n, row + 1, col);
    int right = dfs(grid, empty_count - 1, m, n, row, col + 1);
    int left = dfs(grid, empty_count - 1, m, n, row, col - 1);
    grid[row][col] = 0;
    return up + down + right + left;
  }

public:
  int uniquePathsIII(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int empty_count = 1;
    int row, col;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          row = i, col = j;
        } else if (grid[i][j] == 0) {
          empty_count++;
        }
      }
    }
    return dfs(grid, empty_count, m, n, row, col);
  }
};
