#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int maxScore(vector<int> &A) {
  int n = A.size();
  sort(A.begin(), A.end());

  vector<long long> prefix(n);
  prefix[0] = A[0];

  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + A[i];
  }

  long long ans = LLONG_MIN;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
      long long score = sum + A[i] - A[j];
      ans = max(ans, score);
    }
  }

  return ans;
}
int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int bestAns = maxScore(arr);
  std::cout << bestAns;
  return 0;
}
