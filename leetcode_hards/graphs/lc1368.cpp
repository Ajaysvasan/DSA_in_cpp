#include <climits>
#include <deque>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    deque<pair<int, int>> dq;
    dist[0][0] = 0;
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    dq.push_front({0, 0});
    while (!dq.empty()) {
      auto [curr_row, curr_col] = dq.front();
      dq.pop_front();
      for (int i = 0; i < 4; i++) {
        int nr = dr[i] + curr_row;
        int nc = dc[i] + curr_col;
        if (nr < 0 || nc < 0 || nr >= m || nc >= n)
          continue;
        int edgeCost;
        if (grid[curr_row][curr_col] == i + 1) {
          edgeCost = 0;
        } else {
          edgeCost = 1;
        }
        int newCost = edgeCost + dist[curr_row][curr_col];
        if (newCost < dist[nr][nc]) {
          dist[nr][nc] = newCost;
          if (edgeCost == 0)
            dq.push_front({nr, nc});
          else
            dq.push_back({nr, nc});
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};
