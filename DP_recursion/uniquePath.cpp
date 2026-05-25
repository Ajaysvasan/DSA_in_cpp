#include <iostream>
#include <vector>

int dfs(int m, int n, int currentRow, int currentCol) {
  if (currentRow == m - 1 && currentCol == n - 1) {
    return 1;
  }
  if (currentCol >= n || currentRow >= m)
    return 0;
  return dfs(m, n, currentRow + 1, currentCol) +
         dfs(m, n, currentRow, currentCol + 1);
}

int dfs(int m, int n, int currentRow, int currentCol,
        std::vector<std::vector<int>> &memo) {
  if (currentRow == m - 1 && currentCol == n - 1) {
    return 1;
  }
  if (currentCol >= n || currentRow >= m)
    return 0;
  if (memo[currentRow][currentCol] != -1)
    return memo[currentRow][currentCol];
  return memo[currentRow][currentCol] = dfs(m, n, currentRow + 1, currentCol) +
                                        dfs(m, n, currentRow, currentCol + 1);
}

int uniquePath(int m, int n) {
  std::vector<std::vector<int>> memo(m, std::vector<int>(n + 1, -1));
  return dfs(m, n, 0, 0, memo);
}

int uniquePathTab(int m, int n) {
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}
int uniquePathSO(int m, int n) {
  std::vector<int> dp(n, 1);
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[j] = dp[j] + dp[j - 1];
    }
  }
  return dp[n - 1];
}

int main(int argc, char *argv[]) {
  int m = 3, n = 2;
  std::cout << uniquePathSO(m, n);
  return 0;
}
