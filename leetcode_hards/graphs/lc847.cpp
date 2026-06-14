#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    int n = graph.size();
    int full_mask = (1 << n) - 1;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
    for (int node = 0; node < n; node++) {
      int mask = 1 << node;
      q.push({node, mask});
      visited[node][mask] = true;
    }
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [node, mask] = q.front();
        q.pop();
        if (mask == full_mask)
          return steps;
        for (int neighbour : graph[node]) {
          int new_mask = mask | (1 << neighbour);
          if (!visited[neighbour][new_mask]) {
            visited[neighbour][new_mask] = true;
            q.push({neighbour, new_mask});
          }
        }
      }
      steps++;
    }
    return -1;
  }
};
