#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    // max heap: {distance, {x, y}}
    priority_queue<pair<int, pair<int, int>>> maxHeap;

    for (auto &p : points) {
      int dist = p[0] * p[0] + p[1] * p[1];
      maxHeap.push({dist, {p[0], p[1]}});

      if (maxHeap.size() > k) {
        maxHeap.pop(); // remove farthest point
      }
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) {
      auto pt = maxHeap.top().second;
      result.push_back({pt.first, pt.second});
      maxHeap.pop();
    }

    return result;
  }
};

int main() {
  vector<vector<int>> points = {{1, 3}, {-2, 2}};
  Solution s;
  vector<vector<int>> res = s.kClosest(points, 2);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i][0] << "\n" << res[i][0];
  }
}
