#include <iostream>
#include <vector>

using namespace std;

// DFS function to detect cycle in an undirected graph
bool hasCycleDFS(int u, int parent, vector<int> adj[], vector<bool> &visited,
                 int &count) {
  visited[u] = true;
  count++; // Increment count when a new node is visited

  for (int v : adj[u]) {
    if (!visited[v]) {
      if (hasCycleDFS(v, u, adj, visited, count))
        return true;
    }
    // If an adjacent node is visited and is NOT the parent, it's a cycle
    else if (v != parent) {
      return true;
    }
  }
  return false;
}

int main() {
  int V, E;
  if (!(cin >> V >> E))
    return 0;

  // Use a vector array for adjacency list
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    // Since it's undirected, add edges for both directions
    if (u < V && v < V) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  vector<bool> visited(V, false);
  int nodesVisited = 0;
  bool foundCycle = false;

  // The loop handles disconnected components
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      if (hasCycleDFS(i, -1, adj, visited, nodesVisited)) {
        foundCycle = true;
        break; // Stop immediately once a cycle is found
      }
    }
  }

  cout << (foundCycle ? 1 : 0) << endl;
  cout << "Number of nodes visited: " << nodesVisited << endl;

  return 0;
}
