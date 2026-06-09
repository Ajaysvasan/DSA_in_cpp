#include <vector>
using namespace std;
class Solution {
private:
  vector<int> subtreeSize;
  vector<int> answer;
  vector<vector<int>> graph;

  void dfs1(int node, int parent, int depth) {
    subtreeSize[node] = 1;

    answer[0] += depth;

    for (int child : graph[node]) {
      if (child == parent)
        continue;

      dfs1(child, parent = node, depth + 1);

      subtreeSize[node] += subtreeSize[child];
    }
  }

  void dfs2(int node, int parent, int n) {
    for (int child : graph[node]) {
      if (child == parent)
        continue;

      answer[child] = answer[node] + n - 2 * subtreeSize[child];

      dfs2(child, node, n);
    }
  }

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    graph.resize(n);

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];

      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    subtreeSize.assign(n, 0);
    answer.assign(n, 0);

    dfs1(0, -1, 0);

    dfs2(0, -1, n);

    return answer;
  }
};
