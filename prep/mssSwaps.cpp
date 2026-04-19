#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int maxSubarraySumWithKSwaps(vector<int> &nums, int k) {
  int n = nums.size();

  // Get k largest elements (replacement pool)
  vector<int> sorted = nums;
  sort(sorted.begin(), sorted.end(), greater<int>());

  vector<int> best;
  for (int i = 0; i < min(k, n); i++) {
    best.push_back(sorted[i]);
  }

  // DP array
  vector<vector<ll>> dp(n, vector<ll>(k + 1, LLONG_MIN));

  // Base case
  for (int j = 0; j <= k; j++) {
    dp[0][j] = nums[0];
    if (j > 0 && !best.empty()) {
      dp[0][j] = max(dp[0][j], (ll)best[0]);
    }
  }

  ll answer = dp[0][0];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {

      // Option 1: take current element
      dp[i][j] = max((ll)nums[i], dp[i - 1][j] + nums[i]);

      // Option 2: use swap (replace with best[j-1])
      if (j > 0 && j - 1 < best.size()) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + best[j - 1]);
      }

      answer = max(answer, dp[i][j]);
    }
  }

  return answer;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << maxSubarraySumWithKSwaps(nums, k) << endl;
}
