#include <bits/stdc++.h>

int frontPartition(std::vector<int> &arr, int k, int idx,
                   std::vector<int> &dp) {
  if (idx >= arr.size())
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int len = 0, max_value = INT_MIN, max_ans = INT_MIN;
  for (int i = idx; i < std::min((int)arr.size(), idx + k); i++) {
    len++;
    max_value = std::max(max_value, arr[i]);
    int sum = (len * max_value) + frontPartition(arr, k, i + 1, dp);
    max_ans = std::max(max_ans, sum);
  }
  return dp[idx] = max_ans;
}

int partitionSum(std::vector<int> &arr, int k) {
  std::vector<int> dp(arr.size(), -1);
  return frontPartition(arr, k, 0, dp);
}

int partitionSumTab(std::vector<int> &arr, int k) {
  std::vector<int> dp(arr.size() + 1, 0);
  for (int i = arr.size() - 1; i >= 0; i--) {
    int len = 0, max_ans = INT_MIN, max_value = INT_MIN;
    for (int j = i; j < std::min((int)arr.size(), i + k); j++) {
      len++;
      max_value = std::max(max_value, arr[j]);
      int sum = (len * max_value) + dp[j + 1];
      max_ans = std::max(max_ans, sum);
    }
    dp[i] = max_ans;
  }
  return dp[0];
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
  int k = 3;
  std::cout << partitionSumTab(arr, k);
  return 0;
}
