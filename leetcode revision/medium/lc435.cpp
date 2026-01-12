#include <algorithm>
#include <iostream>
#include <pthread.h>
#include <vector>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    int count = 0, current_active_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] >= current_active_end) {
        current_active_end = intervals[i][1];
      } else {
        count++;
      }
    }
    return count;
  }
};
int main() {
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  Solution s;
  cout << s.eraseOverlapIntervals(intervals);
  return 0;
}
