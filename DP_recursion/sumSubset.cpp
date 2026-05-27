#include <iostream>
#include <vector>

bool dfs(std::vector<int> &arr, int target, std::vector<std::vector<int>> &memo,
         int idx) {
  if (target == 0)
    return true;
  if (target < 0 || idx >= arr.size())
    return false;
  if (memo[idx][target] != -1)
    return memo[idx][target] == 1;

  bool take = dfs(arr, target - arr[idx], memo, idx + 1);
  bool leave = dfs(arr, target, memo, idx + 1);
  bool result = take || leave;
  memo[idx][target] = result ? 1 : 0;
  return result;
}

bool isSubSetSumMemo(std::vector<int> &arr) {
  int sum = 0;
  for (int value : arr)
    sum += value;
  if (sum % 2 != 0)
    return false;
  int target = sum / 2;
  std::vector<std::vector<int>> memo(arr.size(),
                                     std::vector<int>(target + 1, -1));
  return dfs(arr, target, memo, 0);
}

bool isSubSetSumTab(std::vector<int> &arr) {
  int sum = 0;
  for (int value : arr) {
    sum += value;
  }
  if (sum % 2 != 0)
    return false;
  int target = sum / 2;

  std::vector<std::vector<int>> dp(arr.size() + 1,
                                   std::vector<int>(target + 1, -1));
  for (int i = 0; i <= arr.size(); i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= arr.size(); i++) {
    for (int j = 1; j <= target; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[arr.size()][target];
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 5, 11, 5};
  if (isSubSetSumTab(arr)) {
    std::cout << "True\n";
  } else {
    std::cout << "false\n";
  }
  return 0;
}
