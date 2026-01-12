#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(),
                                                           nums.end());

    while (k--) {
      int x = minHeap.top();
      minHeap.pop();
      minHeap.push(-x);
    }

    int sum = 0;
    while (!minHeap.empty()) {
      sum += minHeap.top();
      minHeap.pop();
    }
    return sum;
  }
};
