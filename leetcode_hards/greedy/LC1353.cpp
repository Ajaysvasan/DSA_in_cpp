#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
class Solution {
public:
  int maxEvents(std::vector<std::vector<int>> &events) {
    int n = events.size();
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
      maxValue = std::max(maxValue, events[i][1]);
    }
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    std::sort(events.begin(), events.end());
    int ans = 0;
    for (int i = 0, j = 0; i <= maxValue; i++) {
      while (j < n && events[j][0] <= i) {
        pq.emplace(events[j][1]);
        j++;
      }
      while (!pq.empty() && pq.top() < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
        ans++;
      }
    }
    return ans;
  }
};
