#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printZigZag(const vector<vector<int>> &mat) {
  if (mat.empty() || mat[0].empty())
    return;

  int n = mat.size();
  int m = mat[0].size();

  // The maximum possible sum of row + col is (n-1) + (m-1) = n + m - 2
  int maxSum = n + m - 2;

  for (int sum = 0; sum <= maxSum; sum++) {

    // If the sum is EVEN, we move Up-Right (Row decreases)
    if (sum % 2 == 0) {
      // Start at the maximum possible row for this sum
      int startRow = min(sum, n - 1);
      // End at the minimum possible row for this sum
      int endRow = max(0, sum - m + 1);

      for (int row = startRow; row >= endRow; row--) {
        int col = sum - row;
        cout << mat[row][col] << " ";
      }
    }
    // If the sum is ODD, we move Down-Left (Row increases)
    else {
      // Start at the minimum possible row for this sum
      int startRow = max(0, sum - m + 1);
      // End at the maximum possible row for this sum
      int endRow = min(sum, n - 1);

      for (int row = startRow; row <= endRow; row++) {
        int col = sum - row;
        cout << mat[row][col] << " ";
      }
    }
  }
  cout << "\n";
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printZigZag(matrix);
  // Output: 1 2 4 7 5 3 6 8 9

  return 0;
}
