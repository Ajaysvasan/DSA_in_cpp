#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  double mincostToHireWorkers(std::vector<int> &quality, std::vector<int> &wage,
                              int k) {
    int n = quality.size();
    std::vector<std::pair<double, int>> wageToQualityRatio;
    double totalCost = std::numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
      double ratio = (double)wage[i] / quality[i];
      wageToQualityRatio.push_back({ratio, quality[i]});
    }
    std::sort(wageToQualityRatio.begin(), wageToQualityRatio.end());
    std::priority_queue<int> pq;
    int currentTotalQuality = 0;
    for (int i = 0; i < n; i++) {
      double currentRatio = wageToQualityRatio[i].first;
      int currentQuality = wageToQualityRatio[i].second;
      currentTotalQuality += currentQuality;
      pq.push(currentQuality);
      if (pq.size() > k) {
        currentTotalQuality -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        totalCost = std::min(totalCost, currentTotalQuality * currentRatio);
      }
    }
    return totalCost;
  }
};
