#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int fresh_orange_count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          fresh_orange_count++;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    if (fresh_orange_count == 0)
      return 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    int count = 0;
    while (!q.empty()) {
      bool rottedThisMin = false;
      int size = q.size();
      for (int k = 0; k < size; k++) {

        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nr = dr[i] + row;
          int nc = dc[i] + col;
          if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() ||
              grid[nr][nc] == 0 || grid[nr][nc] != 1) {
            continue;
          }
          grid[nr][nc] = 2;
          fresh_orange_count--;
          q.push({nr, nc});
          rottedThisMin = true;
        }
      }
      if (rottedThisMin)
        count++;
    }
    return (fresh_orange_count == 0) ? count : -1;
  }
};
