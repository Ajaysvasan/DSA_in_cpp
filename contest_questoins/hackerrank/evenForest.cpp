#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, const vector<vector<int>> &adj, int &removed_edges)
{
    int current_subtree_size = 1; 

    for (int neighbor : adj[node])
    {
        if (neighbor != parent)
        { 
            int child_subtree_size = dfs(neighbor, node, adj, removed_edges);

            
            if (child_subtree_size % 2 == 0)
            {
                removed_edges++;
            }
            else
            {
                
                current_subtree_size += child_subtree_size;
            }
        }
    }

    return current_subtree_size;
}

int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to)
{

    vector<vector<int>> adj(t_nodes + 1);
    for (int i = 0; i < t_edges; i++)
    {
        adj[t_from[i]].push_back(t_to[i]);
        adj[t_to[i]].push_back(t_from[i]);
    }

    int removed_edges = 0;
    dfs(1, 0, adj, removed_edges);

    return removed_edges;
}
int main()
{
}