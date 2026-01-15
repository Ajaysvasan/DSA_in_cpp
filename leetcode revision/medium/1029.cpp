#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    int first_n = costs.size() / 2;
    int assigned_to_a = 0;
    int cost = 0;
    for (int i = 0; i < costs.size(); i++) {
      heap.push({costs[i][0] - costs[i][1], i});
    }
    while (!heap.empty()) {
      int x = heap.top().second;
      if (assigned_to_a < first_n) {
        cost += costs[x][0];
      } else {
        cost += costs[x][1];
      }
      heap.pop();
    }
    return cost;
  }
};
