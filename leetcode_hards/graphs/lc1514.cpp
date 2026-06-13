#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {
    vector<pair<int, double>> adj[n];
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
      adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    vector<double> probability(n, 0.0);
    probability[start_node] = 1.0;
    pq.push({1.0, start_node});
    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int curr_node = it.second;
      double curr_prob = it.first;
      for (auto iter : adj[curr_node]) {
        int adjNode = iter.first;
        double adjProb = iter.second;
        double newProb = adjProb * curr_prob;
        if (newProb > probability[adjNode]) {
          probability[adjNode] = newProb;
          pq.push({newProb, adjNode});
        }
      }
    }

    return probability[end_node];
  }
};
