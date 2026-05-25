#include <iostream>
#include <vector>

int dfs(std::vector<int> &arr, int idx, int currentSum) {
  if (idx >= arr.size())
    return currentSum;

  int right = dfs(arr, idx + 2, currentSum + arr[idx]);
  int left = dfs(arr, idx + 1, currentSum);
  return std::max(right, left);
}

int dfs(std::vector<int> &arr, int idx) {
  if (idx >= arr.size()) {
    return 0;
  }
  return std::max(arr[idx] + dfs(arr, idx + 2), dfs(arr, idx + 1));
}

int dfs(std::vector<int> &arr, int idx, std::vector<int> &memo) {
  if (idx >= arr.size()) {
    return 0;
  }
  if (memo[idx] != -1)
    return memo[idx];
  return memo[idx] = std::max(arr[idx] + dfs(arr, idx + 2), dfs(arr, idx + 1));
}

int houseRobberRec(std::vector<int> &arr) {
  std::vector<int> memo(arr.size() + 1, -1);
  return dfs(arr, 0, memo);
}

int houseRobberTab(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<int> dp(arr.size() + 1, -1);
  dp[0] = 0;
  dp[1] = arr[0];
  for (int i = 2; i <= n; i++) {
    dp[i] = std::max(arr[i - 1] + dp[i - 2], dp[i - 1]);
  }
  return dp[n];
}

int houseRobberSO(std::vector<int> &arr) {
  int n = arr.size();
  int prevOne = 0;
  int prevTwo = arr[0];
  int current = 0;
  for (int i = 2; i <= n; i++) {
    current = std::max(prevTwo, arr[i - 1] + prevOne);
    prevOne = prevTwo;
    prevTwo = current;
  }
  return current;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 7, 9, 3, 1};

  std::cout << houseRobberSO(arr);
  return 0;
}
