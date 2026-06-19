#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &location, int k, int maxDist) {

  int centersUsed = 0;
  int n = location.size();

  int i = 0;

  while (i < n) {

    centersUsed++;

    if (centersUsed > k)
      return false;

    int coverUntil = location[i] + 2 * maxDist;

    while (i < n && location[i] <= coverUntil)
      i++;
  }

  return true;
}

int getMaximumDistance(vector<int> &location, int k) {

  sort(location.begin(), location.end());

  int low = 0;

  int high = location.back() - location.front();

  int answer = high;

  while (low <= high) {

    int mid = low + (high - low) / 2;

    if (isPossible(location, k, mid)) {

      answer = mid;
      high = mid - 1;

    } else {

      low = mid + 1;
    }
  }

  return answer;
}

int main() {

  vector<int> location = {4, 1, 6, 7, 2};

  int k = 2;

  cout << getMaximumDistance(location, k) << endl;

  return 0;
}
