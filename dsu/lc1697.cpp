#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> size, parent;

public:
  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int node) {
    if (parent[node] == node) {
      return node;
    }
    return parent[node] = find(parent[node]);
  }
  bool unite(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u == parent_v)
      return false;
    if (size[parent_u] < size[parent_v])
      swap(parent_u, parent_v);
    parent[parent_v] = parent_u;
    size[parent_u] += size[parent_v];
    return true;
  }
};

class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList,
                                         vector<vector<int>> &queries) {
    sort(edgeList.begin(), edgeList.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
    for (int i = 0; i < queries.size(); i++) {
      queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
    DSU dsu(n);
    int j = 0;
    vector<bool> ans(queries.size(), false);
    for (vector<int> &query : queries) {
      while (j < edgeList.size() && edgeList[j][2] < query[2]) {
        dsu.unite(edgeList[j][0], edgeList[j][1]);
        j++;
      }
      ans[query[3]] = dsu.find(query[0]) == dsu.find(query[1]);
    }
    return ans;
  }
};
