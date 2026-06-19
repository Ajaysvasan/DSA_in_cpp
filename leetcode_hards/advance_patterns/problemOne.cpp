#include <bits/stdc++.h>
using namespace std;

bool canAchieve(vector<int> &pos, int k, int maxGap) {
  long long needed = 0;

  for (int i = 1; i < pos.size(); i++) {
    int gap = pos[i] - pos[i - 1];
    needed += (gap - 1) / maxGap;

    if (needed > k)
      return false;
  }

  return needed <= k;
}

int minimizeMaxGap(vector<int> &pos, int k) {
  int low = 1;
  int high = 0;

  for (int i = 1; i < pos.size(); i++) {
    high = max(high, pos[i] - pos[i - 1]);
  }

  int ans = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (canAchieve(pos, k, mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> positions = {1, 10, 13, 17, 20, 31};
  int k = 3;

  cout << minimizeMaxGap(positions, k) << endl;

  return 0;
}
