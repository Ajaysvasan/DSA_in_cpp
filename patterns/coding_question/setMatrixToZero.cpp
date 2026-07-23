#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int m, n;
  std::cin >> m >> n;
  std::vector<bool> rows(m, false);
  std::vector<bool> cols(n, false);
  std::vector<std::vector<int>> arr(m, std::vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 0) {
        rows[i] = true;
        cols[j] = true;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (rows[i] || cols[j]) {
        arr[i][j] = 0;
      }
    }
  }
  return 0;
}
