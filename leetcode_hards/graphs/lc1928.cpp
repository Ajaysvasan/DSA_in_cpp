#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    int n = passingFees.size(); // Use n (number of nodes), not edges.size()

    vector<vector<pair<int, int>>> adj(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<int> minTimeVisited(n, 1e9);

    pq.push({passingFees[0], 0, 0});

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int curr_cost = curr[0];
      int curr_time = curr[1];
      int curr_node = curr[2];

      if (curr_node == n - 1) {
        return curr_cost;
      }

      if (curr_time >= minTimeVisited[curr_node]) {
        continue;
      }

      minTimeVisited[curr_node] = curr_time;

      for (const auto &neighbor : adj[curr_node]) {
        int next_node = neighbor.first;
        int travel_time = neighbor.second;

        int next_time = curr_time + travel_time;
        int next_cost = curr_cost + passingFees[next_node];

        if (next_time <= maxTime) {
          pq.push({next_cost, next_time, next_node});
        }
      }
    }

    return -1;
  }
};
