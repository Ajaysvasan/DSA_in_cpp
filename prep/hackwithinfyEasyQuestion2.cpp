#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  unordered_map<int, int> mpp;
  int sum = 0, max_sum = 0;
  int left = 0;
  for (int i = 0; i < n; i++) {

    mpp[arr[i]]++;

    sum += arr[i];
    while (!mpp.empty() && mpp.size() > k) {
      mpp[arr[left]]--;
      if (mpp[arr[left]] == 0) {
        mpp.erase(arr[left]);
      }
      sum = sum - arr[left];
      left++;
    }
    max_sum = max(max_sum, sum);
  }
  cout << max_sum;
}
