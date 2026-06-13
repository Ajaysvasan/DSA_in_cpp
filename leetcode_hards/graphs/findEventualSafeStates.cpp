#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> reversedGraph(n);
    vector<int> out_degree(n, 0);
    for (int i = 0; i < n; i++) {
      out_degree[i] = graph[i].size();
      for (int v : graph[i]) {
        reversedGraph[v].push_back(i);
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (out_degree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      res.push_back(node);
      for (int parent_node : reversedGraph[node]) {
        out_degree[parent_node]--;
        if (out_degree[parent_node] == 0) {
          q.push(parent_node);
        }
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
