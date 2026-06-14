#include <vector>
using namespace std;

class DSU {
  vector<int> rank, parent;

public:
  DSU(int n) {
    rank.resize(n, 0);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int findUPar(int node) {
    if (node == parent[node])
      return parent[node];
    return parent[node] = findUPar(parent[node]);
  }
  void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      parent[ulp_v] = ulp_u;
    } else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};
class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1)
      return -1;
    DSU dsu(n);
    for (const auto &connection : connections) {
      dsu.unionByRank(connection[0], connection[1]);
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
      if (dsu.findUPar(i) == i)
        components++;
    }
    return components - 1;
  }
};
