#include <algorithm>
#include <iostream>
#include <vector>

// 9 9 4
// 6 6 8
// 2 1 1
//
// The question is to find the longest path which is in strictly increasing
// order So the output for this program is 1->2->6->9 is the path and the count
// is 4

int dfs(int r, int c, int n, std::vector<std::vector<int>> &matrix,
        std::vector<std::vector<int>> &memo) {
  // If we already calculated the longest path starting from this cell, return
  // it
  if (memo[r][c] != 0)
    return memo[r][c];

  int max_len = 1; // Every cell is a path of at least length 1
  std::vector<std::pair<int, int>> directions = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  for (auto [dr, dc] : directions) {
    int nr = r + dr, nc = c + dc;
    // Check boundaries and if the next cell is strictly INCREASING
    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
        matrix[nr][nc] > matrix[r][c]) {
      max_len = std::max(max_len, 1 + dfs(nr, nc, n, matrix, memo));
    }
  }

  return memo[r][c] = max_len;
}

int main() {
  int n;
  if (!(std::cin >> n))
    return 0;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      std::cin >> matrix[i][j];

  int overall_max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      overall_max = std::max(overall_max, dfs(i, j, n, matrix, memo));
    }
  }

  std::cout << overall_max << std::endl;
  return 0;
}
