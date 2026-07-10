#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v)
    {
        int parent_u = find(u);
        int parent_v = find(v);
        if (parent_u == parent_v)
            return;
        if (parent_u < parent_v)
        {
            parent[parent_v] = parent_u;
            // size[parent_u] += size[parent_v];
        }
        else
        {
            parent[parent_u] = parent_v;
            // size[parent_v] += size[parent_u];
        }
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU dsu(26);
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            dsu.unite(s1[i] - 'a', s2[i] - 'a');
        }
        string result = "";
        for (int i = 0; i < baseStr.size(); i++)
        {
            result += dsu.find(baseStr[i] - 'a') + 'a';
        }
        return result;
    }
};