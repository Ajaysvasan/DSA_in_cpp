#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int node) {
    if (parent[node] == node) {
      return node;
    }
    return parent[node] = find(parent[node]);
  }
  void unite(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u == parent_v) {
      return;
    }
    if (size[parent_u] < size[parent_v]) {
      swap(parent_u, parent_v);
    }
    parent[parent_v] = parent_u;
    size[parent_u] += size[parent_v];
  }
};

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    DSU dsu(n);
    vector<int> edgeCount(n, 0);
    for (vector<int> &edge : edges) {
      dsu.unite(edge[0], edge[1]);
    }

    for (vector<int> &edge : edges) {
      int u = edge[0];
      int root = dsu.find(u);
      edgeCount[root]++;
    }
    int count = 0;
    for (int root = 0; root < n; root++) {
      if (dsu.find(root) != root) {
        continue;
      }
      long long k = dsu.size[root];
      long long required_edges = k * (k - 1) / 2;
      if (required_edges == edgeCount[root]) {
        count++;
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
  Solution sol;
  cout << sol.countCompleteComponents(n, edges);
  return 0;
}
