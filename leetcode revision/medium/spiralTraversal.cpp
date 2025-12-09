#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix) {
  vector<int> result;

  int n = matrix.size();
  int m = matrix[0].size();

  int top = 0, bottom = n - 1;
  int left = 0, right = m - 1;

  while (top <= bottom && left <= right) {
    for (int col = left; col <= right; col++)
      result.push_back(matrix[top][col]);
    top++;
    for (int row = top; row <= bottom; row++)
      result.push_back(matrix[row][right]);
    right--;
    if (top <= bottom) {
      for (int col = right; col >= left; col--)
        result.push_back(matrix[bottom][col]);
      bottom--;
    }

    if (left <= right) {
      for (int row = bottom; row >= top; row--)
        result.push_back(matrix[row][left]);
      left++;
    }
  }

  return result;
}
