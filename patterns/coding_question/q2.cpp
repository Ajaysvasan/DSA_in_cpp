#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
  int prefix = 0;
  int total = 0;
  for (int num : arr)
    total += num;
  for (int i = 0; i < arr.size(); i++) {
    int rightSum = total - prefix - arr[i];
    if (rightSum == prefix) {
      cout << i;
      return 0;
    }
    prefix += arr[i];
  }
  cout << -1;
  return 0;
}
