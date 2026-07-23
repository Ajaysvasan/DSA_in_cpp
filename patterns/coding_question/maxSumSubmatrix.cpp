#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Standard Kadane's Algorithm
int kadane(vector<int> &arr) {
  int maxEndingHere = arr[0];
  int maxSoFar = arr[0];

  for (int i = 1; i < arr.size(); i++) {
    maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
    maxSoFar = max(maxSoFar, maxEndingHere);
  }

  return maxSoFar;
}

int maximumSumSubmatrix(vector<vector<int>> &matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  int answer = INT_MIN;

  // Fix the left column
  for (int left = 0; left < cols; left++) {

    // Temporary array to store compressed row sums
    vector<int> temp(rows, 0);

    // Expand the right column
    for (int right = left; right < cols; right++) {

      // Compress the rows
      for (int row = 0; row < rows; row++)
        temp[row] += matrix[row][right];

      // Apply Kadane on compressed array
      answer = max(answer, kadane(temp));
    }
  }

  return answer;
}

int main() {

  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> matrix(rows, vector<int>(cols));

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cin >> matrix[i][j];

  cout << maximumSumSubmatrix(matrix);

  return 0;
}
