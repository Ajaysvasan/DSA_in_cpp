#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    if (intervals.empty())
      return 0;

    // 1. Sort meetings by start time
    sort(intervals.begin(), intervals.end());

    // 2. Min-heap to track earliest ending meeting
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto &meeting : intervals) {
      int start = meeting[0];
      int end = meeting[1];

      // If the earliest meeting ends before current starts, reuse room
      if (!minHeap.empty() && minHeap.top() <= start) {
        minHeap.pop();
      }

      // Allocate room (new or reused)
      minHeap.push(end);
    }

    // 3. Heap size = number of rooms needed
    return minHeap.size();
  }
};
