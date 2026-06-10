#include <algorithm>
#include <vector>
class Solution {
public:
  int maxSatisfaction(std::vector<int> &satisfaction) {
    std::sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    int total = 0, res = 0;
    for (int i = n - 1; i >= 0 && satisfaction[i] > -total; --i) {
      total += satisfaction[i];
    }
    return total;
  }
};
