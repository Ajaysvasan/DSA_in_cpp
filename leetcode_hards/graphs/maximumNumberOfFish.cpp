#include <vector>
using namespace std;
class Solution {
  int dfs(vector<vector<int>> &grid, int row, int col, int m, int n) {
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
      return 0;
    }
    int caughtFish = grid[row][col];
    grid[row][col] = 0;
    caughtFish += dfs(grid, row, col + 1, m, n);
    caughtFish += dfs(grid, row, col - 1, m, n);
    caughtFish += dfs(grid, row + 1, col, m, n);
    caughtFish += dfs(grid, row - 1, col, m, n);

    return caughtFish;
  }

public:
  int findMaxFish(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // vector<vector<int>>dp( m , vector<int>(n , -1));
    int max_value = -1;
    for (int i = 0; i < m; i++) {
      // int currnet_value = 0;
      for (int j = 0; j < n; j++) {
        int current_value = dfs(grid, i, j, m, n);
        max_value = max(max_value, current_value);
      }
    }
    return max_value;
  }
};
