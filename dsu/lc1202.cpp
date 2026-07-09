#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> size;
  vector<int> parent;

public:
  DSU(int n) {
    parent.resize(n);
    size.resize(n, 1);
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
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) {
      return;
    }
    if (size[pu] < size[pv])
      swap(pu, pv);

    parent[pv] = pu;
    size[pu] += size[pv];
  }
};

class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.size();
    DSU dsu(n);

    for (const auto &p : pairs) {
      dsu.unite(p[0], p[1]);
    }

    unordered_map<int, priority_queue<char, vector<char>, greater<char>>>
        components;

    for (int i = 0; i < n; i++) {
      int root = dsu.find(i);
      components[root].push(s[i]);
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
      int root = dsu.find(i);
      ans += components[root].top();
      components[root].pop();
    }

    return ans;
  }
};
