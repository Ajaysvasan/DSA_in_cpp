#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  int shortestPath(int n, std::vector<std::vector<int>> &edges,
                   std::string labels, int k) {
    std::vector<std::pair<int, int>> graph[n];
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int weight = edges[i][2];
      // directed graph
      graph[u].push_back({v, weight});
    }
    std::vector<int> dist(n, 1e9);
    std::unordered_map<char, int> labelsVisited;
    // Since we start from 0th node
    labelsVisited[0] = 1;
    dist[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    // Weight , node
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [curr_weight, curr_node] = pq.top();
      pq.pop();
      if (labelsVisited.size() >= k || curr_weight > dist[curr_node])
        continue;
      if (curr_node == n - 1)
        return dist[curr_node];
      for (auto neighbor : graph[curr_node]) {
        int neighbor_node = neighbor.first;
        int neighbor_weight = neighbor.second;
        if (labelsVisited.find(labels[neighbor_node]) != labelsVisited.end() &&
            labelsVisited[labels[neighbor_node]] <= k) {
          labelsVisited[labels[neighbor_node]]++;
          int new_weight = curr_weight + neighbor_weight;
          if (new_weight < dist[neighbor_node]) {
            dist[neighbor_node] = new_weight;
            pq.push({new_weight, neighbor_node});
          }
        }
      }
    }
    return 0;
  }
};

struct State {
  int weight;
  int node;
  vector<int> label_counts;

  bool operator>(const State &other) const { return weight > other.weight; }
};

class OptimalSolution {
public:
  int shortestPath(int n, vector<vector<int>> &edges, string labels, int k) {
    vector<pair<int, int>> graph[n];
    for (auto &edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
    }

    // Priority Queue using our custom State
    priority_queue<State, vector<State>, greater<State>> pq;

    // 2. Initialize the starting state
    vector<int> start_counts(26, 0); // Assuming lowercase English letters
    start_counts[labels[0] - 'a'] = 1;
    pq.push({0, 0, start_counts});

    // 3. We need a 2D/3D distance array or a visited set that accounts for the
    // state. If state tracking is complex, a localized dist check is required.
    // For simplicity, we omit the complex DP array here, but beware of TLE if
    // you don't memoize states.

    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.node == n - 1)
        return curr.weight;

      for (auto neighbor : graph[curr.node]) {
        int next_node = neighbor.first;
        int next_weight = neighbor.second;
        char next_label = labels[next_node];

        // Copy the current path's history to pass to the neighbor
        vector<int> next_counts = curr.label_counts;

        // Check if adding this new node violates the specific path's limit
        if (next_counts[next_label - 'a'] < k) {

          next_counts[next_label - 'a']++;

          // Push the new independent state into the queue
          pq.push({curr.weight + next_weight, next_node, next_counts});
        }
      }
    }
    return -1; // Standard return for unreachable in shortest path
  }
};
