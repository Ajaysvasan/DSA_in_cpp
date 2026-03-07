#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>

// Undirected graph
class Graph {
private:
  std::unordered_map<int, std::vector<int>> adj;

public:
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void Bfs(int start) {
    std::set<int> visited;
    std::queue<int> q;
    q.push(start);
    visited.insert(start);
    std::cout << "BFS result: ";
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      std::cout << node << " ";
      for (int neighbour : adj[node]) {
        if (!visited.count(neighbour)) {
          visited.insert(neighbour);
          q.push(neighbour);
        }
      }
    }
    std::cout << "\nBFS complete\n";
  }

  void Dfs(int start) {
    std::set<int> visited;
    std::stack<int> s;
    s.push(start);
    std::cout << "DFS result: ";
    while (!s.empty()) {
      int node = s.top();
      s.pop();
      if (!visited.count(node)) {
        std::cout << node << " ";
        visited.insert(node);
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
          if (!visited.count(*it)) {
            s.push(*it);
          }
        }
      }
    }
    std::cout << "\nDFS completed\n";
  }
  void DFS_revision(int start) {
    std::set<int> visited;
    std::stack<int> s;
    s.push(start);
    std::cout << "DFS: ";
    while (!s.empty()) {
      int node = s.top();
      s.pop();
      if (!visited.count(node)) {
        std::cout << node << " ";
        visited.insert(node);
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
          if (!visited.count(*it)) {
            s.push(*it);
          }
        }
      }
    }
    std::cout << "\nCompleted";
  }
};
int main() {
  // Undirected Graph
  Graph g;
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 6);
  g.addEdge(5, 6);

  g.Bfs(1);
  g.Dfs(1);
  g.DFS_revision(1);

  return 0;
}
