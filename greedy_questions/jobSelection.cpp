#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<int>> jobs = {{1, 2}, {2, 4}, {3, 6}, {4, 8}, {5, 10}};
  sort(jobs.begin(), jobs.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int count = 0;
  int prev_end = jobs[0][1];
  for (int i = 1; i < jobs.size(); i++) {
    if (jobs[i][0] >= prev_end) {
      count++;
      prev_end = jobs[i][1];
    }
  }
  cout << count;
  return 0;
}
