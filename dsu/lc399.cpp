#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class DSU {
public:
  vector<int> parent;
  vector<double> weight;

  DSU(int n) {
    parent.resize(n);
    weight.assign(n, 1.0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] == node) {
      return node;
    }
    int oldParent = parent[node];
    parent[node] = find(parent[node]);
    weight[node] *= weight[oldParent];
    return parent[node];
  }

  bool unite(int u, int v, double value) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v) {
      return false;
    }

    parent[root_u] = root_v;

    weight[root_u] = (value * weight[v]) / weight[u];

    return true;
  }
};

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {

    unordered_map<string, int> str_to_id;
    int id = 0;

    // 1. Map all unique strings to an integer ID dynamically
    for (const auto &eq : equations) {
      if (str_to_id.find(eq[0]) == str_to_id.end()) {
        str_to_id[eq[0]] = id++;
      }
      if (str_to_id.find(eq[1]) == str_to_id.end()) {
        str_to_id[eq[1]] = id++;
      }
    }

    DSU dsu(id);

    // 2. Build the DSU Graph
    for (int i = 0; i < equations.size(); i++) {
      dsu.unite(str_to_id[equations[i][0]], str_to_id[equations[i][1]],
                values[i]);
    }

    // 3. Process Queries
    vector<double> res;
    for (const auto &query : queries) {
      // If either variable was completely unknown, return -1.0
      if (str_to_id.find(query[0]) == str_to_id.end() ||
          str_to_id.find(query[1]) == str_to_id.end()) {
        res.push_back(-1.0);
      } else {
        int u = str_to_id[query[0]];
        int v = str_to_id[query[1]];

        // If they share the same root, we can evaluate the division
        if (dsu.find(u) == dsu.find(v)) {
          // weight[u] is (u / root). weight[v] is (v / root).
          // (u / root) / (v / root) = u / v
          res.push_back(dsu.weight[u] / dsu.weight[v]);
        } else {
          res.push_back(-1.0);
        }
      }
    }

    return res;
  }
};
