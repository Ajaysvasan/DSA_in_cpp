#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll maxOperations;
  cin >> n >> maxOperations;

  vector<ll> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  sort(values.begin(), values.end());

  int left = 0;
  int right = n - 1;

  while (left < right && maxOperations > 0) {

    // Count frequency of left value
    ll leftValue = values[left];
    ll leftCount = 0;
    while (left + leftCount <= right && values[left + leftCount] == leftValue) {
      leftCount++;
    }

    // Count frequency of right value
    ll rightValue = values[right];
    ll rightCount = 0;
    while (right - rightCount >= left &&
           values[right - rightCount] == rightValue) {
      rightCount++;
    }

    // Decide which side to move
    if (leftCount <= rightCount) {
      // Move left side up
      ll nextValue = values[left + leftCount]; // next distinct value
      ll difference = nextValue - leftValue;

      ll cost = difference * leftCount;

      if (cost <= maxOperations) {
        // Apply full move
        for (int i = 0; i < leftCount; i++) {
          values[left + i] = nextValue;
        }
        maxOperations -= cost;
        left += leftCount;
      } else {
        // Partial move
        ll step = maxOperations / leftCount;
        for (int i = 0; i < leftCount; i++) {
          values[left + i] += step;
        }
        break;
      }
    } else {
      // Move right side down
      ll nextValue = values[right - rightCount]; // next distinct value
      ll difference = rightValue - nextValue;

      ll cost = difference * rightCount;

      if (cost <= maxOperations) {
        // Apply full move
        for (int i = 0; i < rightCount; i++) {
          values[right - i] = nextValue;
        }
        maxOperations -= cost;
        right -= rightCount;
      } else {
        // Partial move
        ll step = maxOperations / rightCount;
        for (int i = 0; i < rightCount; i++) {
          values[right - i] -= step;
        }
        break;
      }
    }
  }

  cout << values[right] - values[left] << endl;
}
