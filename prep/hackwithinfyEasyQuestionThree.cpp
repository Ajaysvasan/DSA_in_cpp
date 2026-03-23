#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int happyRange(vector<int> &arr, int c) {
  vector<int> diff(c + 2, 0);
  int net_change = 0;
  for (int i = 0; i < arr.size(); i++) {
    int L, R;
    if (arr[i] == -1) {
      L = 1 - net_change;
      R = c;
    } else if (arr[i] == 1) {
      L = 0;
      R = c - 1 - net_change;
    }
    L = max(0, L);
    R = min(R, c);
    if (L <= R) {
      diff[L]++;
      diff[R + 1]--;
    }
    net_change += arr[i];
  }
  int max_happy = -1;
  int best_X = 0;
  int current_happy = 0;

  for (int x = 0; x <= c; x++) {
    current_happy += diff[x];
    if (current_happy > max_happy) {
      max_happy = current_happy;
      best_X = x;
    }
  }
  return best_X;
}

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << happyRange(arr, c);
  return 0;
}
