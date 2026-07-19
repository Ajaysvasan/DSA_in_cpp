#include <bits/stdc++.h>
using namespace std;
// OPtimal solution
// return (start[0] + start[1]) % 2 == (target[0] + target[1]) % 2;
class Solution {
public:
  bool canReach(vector<int> &start, vector<int> &target) {
    int rowDelta[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colDelta[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    // m x n
    int n = 8, m = 8;
    queue<vector<int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[start[0]][start[1]] = true;
    q.push({0, start[0], start[1]});
    while (!q.empty()) {
      int moves = q.front()[0];
      int current_row = q.front()[1];
      int current_col = q.front()[2];
      q.pop();
      if (moves % 2 == 0 && current_row == target[0] &&
          current_col == target[1])
        return true;
      for (int i = 0; i < 8; i++) {
        int newRow = current_row + rowDelta[i];
        int newCol = current_col + colDelta[i];
        if (newRow < m && newCol < n && newRow >= 0 && newCol >= 0 &&
            !visited[newRow][newCol]) {
          if (newRow == target[0] && newCol == target[1]) {
            if ((moves + 1) % 2 == 0)
              return true;
          }
          visited[newRow][newCol] = true;
          q.push({moves + 1, newRow, newCol});
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> start = {4, 5};
  vector<int> target = {6, 6};
  Solution sol;
  if (sol.canReach(start, target)) {
    cout << "True";
  } else {
    cout << "False";
  }
  return 0;
}
