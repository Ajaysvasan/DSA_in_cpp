#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n, m;
  std::cin >> m >> n;

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> matrix[i][j];
    }
  }
  int top = 0, bottom = m - 1;
  while (top < bottom) {
    for (int col = 0; col < n; col++) {
      int temp = matrix[top][col];
      matrix[top][col] = matrix[bottom][col];
      matrix[bottom][col] = temp;
    }
    top++;
    bottom--;
  }
  for (int i = 0; i < m; i++) {
    for (int col = i + 1; col < n; col++) {
      int temp = matrix[i][col];
      matrix[i][col] = matrix[col][i];
      matrix[col][i] = temp;
    }
  }
  return 0;
}
