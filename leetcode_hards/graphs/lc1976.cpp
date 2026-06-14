#include <queue>
#include <vector>
using namespace std;

class Solution {
  const int MOD = 1e9 + 7;

public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj;
    for (int i = 0; i < roads.size(); i++) {
      adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
      adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    vector<long long> dist(n, 1e9);
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    dist[0] = 0;
    ways[0] = 1;
    // {time , node}
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [curr_time, curr_node] = pq.top();
      if (curr_time < dist[curr_node])
        continue;
      for (const auto &it : adj[curr_node]) {
        int adj_node = it.first;
        long long adj_time = it.second;
        long long new_time = adj_time + curr_time;
        if (new_time < dist[adj_node]) {
          dist[adj_node] = new_time;
          ways[adj_node] = ways[curr_node];
        } else if (new_time == dist[adj_node]) {
          ways[adj_node] = (ways[curr_node] + ways[adj_node]) % MOD;
        }
      }
    }
    return ways[n - 1] % MOD;
  }
};
