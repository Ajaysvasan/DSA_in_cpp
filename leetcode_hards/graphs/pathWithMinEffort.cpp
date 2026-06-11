#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {

    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    pq.push({0, 0, 0});

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!pq.empty()) {
      auto [effort, r, c] = pq.top();
      pq.pop();

      if (r == m - 1 && c == n - 1)
        return effort;

      if (effort > dist[r][c])
        continue;

      for (auto [dr, dc] : directions) {
        int nr = r + dr;
        int nc = c + dc;

        if (nr >= 0 && nc >= 0 && nr < m && nc < n) {

          int edgeWeight = abs(heights[r][c] - heights[nr][nc]);

          int newEffort = max(effort, edgeWeight);

          if (newEffort < dist[nr][nc]) {
            dist[nr][nc] = newEffort;
            pq.push({newEffort, nr, nc});
          }
        }
      }
    }

    return 0;
  }
};
