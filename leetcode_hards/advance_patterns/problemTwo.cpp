#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &machines, int k, int maxLoad) {
    long long requiredSplits = 0;

    for (int load : machines) {
      requiredSplits += (load - 1) / maxLoad;

      if (requiredSplits > k)
        return false;
    }

    return true;
  }

  int minimizeMaximumLoad(vector<int> &machines, int k) {

    int low = 1;

    int high = *max_element(machines.begin(), machines.end());

    int answer = high;

    while (low <= high) {

      int mid = low + (high - low) / 2;

      if (isPossible(machines, k, mid)) {
        answer = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return answer;
  }
};

int main() {

  vector<int> machines = {20, 7, 5};
  int k = 2;

  Solution sol;

  cout << sol.minimizeMaximumLoad(machines, k) << endl;

  return 0;
}
