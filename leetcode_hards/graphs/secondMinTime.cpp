#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int secondMinimum(int n, std::vector<std::vector<int>> &edges, int time,
                    int change) {
    std::vector<std::vector<int>> graph(n + 1);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector<int> minTime(n + 1, INT_MAX);
    std::vector<int> secondMinTime(n + 1, INT_MAX);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    minTime[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
      int currCost = pq.top().first;
      int currNode = pq.top().second;
      pq.pop();

      if (currCost > secondMinTime[currNode])
        continue;

      for (int adjNode : graph[currNode]) {
        int newCost = currCost;

        int cycle = currCost / change;
        if (cycle % 2 == 1) {
          newCost += (change - (currCost % change));
        }

        newCost += time;

        if (newCost < minTime[adjNode]) {
          secondMinTime[adjNode] =
              minTime[adjNode]; // Old min becomes second min
          minTime[adjNode] = newCost;
          pq.push({newCost, adjNode});
        } else if (newCost > minTime[adjNode] &&
                   newCost < secondMinTime[adjNode]) {
          secondMinTime[adjNode] = newCost;
          pq.push({newCost, adjNode});
        }
      }
    }

    return secondMinTime[n];
  }
};
