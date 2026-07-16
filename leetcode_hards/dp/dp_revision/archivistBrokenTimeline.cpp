#include <bits/stdc++.h>
using namespace std;

/*
 * f(i , j){
 *  int ans = 2;
 *  for(int k = i + 1; k < n;k++){
 *  if(nums[k] - nums[i] >= nums[i] - nums[j]){
 *        ans = max( ans , 1 + f(k , i));
 *  }
 *  }
 *  return ans;
 * }
 *
 * */

int helper(vector<int> &nums, int i, int j) {
  if (nums.size() == 1) {
    return 1;
  }
  int ans = 2;
  for (int k = i + 1; k < nums.size(); k++) {
    if (nums[k] - nums[i] >= nums[i] - nums[j]) {
      ans = max(ans, 1 + helper(nums, k, i));
    }
  }
  return ans;
}
int helper(vector<int> &nums, int i, int j, vector<vector<int>> &memo) {
  if (nums.size() == 1) {
    return 1;
  }
  if (memo[i][j] != -1)
    return memo[i][j];
  int ans = 2;
  for (int k = i + 1; k < nums.size(); k++) {
    if (nums[k] - nums[i] >= nums[i] - nums[j]) {
      ans = max(ans, 1 + helper(nums, k, i, memo));
    }
  }
  return memo[i][j] = ans;
}

int helper(vector<int> &nums) {
  int n = nums.size();

  if (n <= 1)
    return n;

  vector<vector<int>> dp(n, vector<int>(n, 2));

  int max_len = 2;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = i + 1; k < n; k++) {

        if (nums[k] - nums[i] >= nums[i] - nums[j]) {

          dp[k][i] = max(dp[k][i], dp[i][j] + 1);
          max_len = max(max_len, dp[k][i]);
        }
      }
    }
  }

  return max_len;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<vector<int>> memo(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << helper(nums);
  return 0;
}
