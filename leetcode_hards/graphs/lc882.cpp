#include <climits>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {

    vector<vector<pair<int, int>>> graph(n);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int cnt = edge[2];

      // Cost to travel from u to v is cnt + 1
      graph[u].push_back({v, cnt + 1});
      graph[v].push_back({u, cnt + 1});
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {

      auto [currDist, node] = pq.top();
      pq.pop();

      if (currDist > dist[node])
        continue;

      for (auto &[next, wt] : graph[node]) {

        if (currDist + wt < dist[next]) {
          dist[next] = currDist + wt;
          pq.push({dist[next], next});
        }
      }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
      if (dist[i] <= maxMoves)
        answer++;
    }

    for (auto &edge : edges) {

      int u = edge[0];
      int v = edge[1];
      int cnt = edge[2];

      int leftReach = 0;
      int rightReach = 0;

      if (dist[u] <= maxMoves)
        leftReach = maxMoves - dist[u];

      if (dist[v] <= maxMoves)
        rightReach = maxMoves - dist[v];

      answer += min(cnt, leftReach + rightReach);
    }

    return answer;
  }
};
