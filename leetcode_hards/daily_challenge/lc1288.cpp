#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, vector<int> &b) {
           if (a[0] == b[0]) {
             return a[1] > b[1];
           } else {
             return a[0] < b[0];
           }
         });
    int overlapping = 0;
    int a = intervals[0][0];
    int b = intervals[0][1];
    for (int i = 1; i < n; i++) {
      if (a <= intervals[i][0] && b >= intervals[i][1]) {
        overlapping++;
      } else {
        a = intervals[i][0];
        b = intervals[i][1];
      }
    }
    return n - overlapping;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<vector<int>> intervals = {{3, 10}, {4, 10}, {5, 11}};
  cout << sol.removeCoveredIntervals(intervals);
  return 0;
}
