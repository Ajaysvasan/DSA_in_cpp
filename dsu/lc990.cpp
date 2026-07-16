#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class DSU {
  vector<int> size;
  vector<int> parent;

public:
  DSU(int n) {
    size.assign(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int node) {
    if (parent[node] == node)
      return node;
    return parent[node] = find(parent[node]);
  }
  bool unite(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u == parent_v) {
      return false;
    }
    if (size[parent_u] < size[parent_v])
      swap(parent_u, parent_v);
    parent[parent_v] = parent_u;
    size[parent_u] += size[parent_v];
    return true;
  }
};

class Solution {
  int id = 0;
  void stringToIntMapping(char variable,
                          unordered_map<char, int> &stringToIntMap) {
    if (stringToIntMap.find(variable) == stringToIntMap.end()) {
      stringToIntMap[variable] = id;
      id++;
    }
  }

public:
  bool equationsPossible(vector<string> &equations) {
    unordered_map<char, int> stringToIntMap;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
      string equation = equations[i];
      stringToIntMapping(equation[0], stringToIntMap);
      stringToIntMapping(equation[equation.size() - 1], stringToIntMap);
    }
    int numberOfVariables = stringToIntMap.size();
    DSU dsu(numberOfVariables);

    for (int i = 0; i < n; i++) {
      string equation = equations[i];
      int leftVariable = stringToIntMap[equation[0]];
      int rightVarible = stringToIntMap[equation[equation.size() - 1]];
      if (equation[1] == '=' && equation[2] == '=')
        dsu.unite(leftVariable, rightVarible);
    }
    for (int i = 0; i < n; i++) {
      string equation = equations[i];
      if (equation[1] == '!') {
        int leftVariable = stringToIntMap[equation[0]];
        int rightVarible = stringToIntMap[equation[equation.size() - 1]];
        if (dsu.find(leftVariable) == dsu.find(rightVarible)) {
          return false;
        }
      }
    }
    return true;
  }
};
