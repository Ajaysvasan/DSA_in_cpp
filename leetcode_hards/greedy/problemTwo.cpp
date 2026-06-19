#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minRemval(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int curr_end = intervals[0][1];
  int count = 0;
  for (int i = 1; i < intervals.size(); i++) {
    if (curr_end > intervals[i][0]) {
      count++;
    } else {
      curr_end = intervals[i][1];
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  cout << minRemval(intervals);
  return 0;
}
