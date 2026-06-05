#include <bits/stdc++.h>

int dfs(std::vector<int> &prices, int idx, bool canBuy,
        std::vector<std::vector<int>> &memo) {
  if (idx >= prices.size())
    return 0;
  if (memo[idx][canBuy] != -1)
    return memo[idx][canBuy];
  int doNothing = dfs(prices, idx + 1, canBuy, memo);
  if (canBuy) {
    int buy = -prices[idx] + dfs(prices, idx + 1, false, memo);
    return memo[idx][canBuy] = std::max(doNothing, buy);
  } else {
    int sell = prices[idx] + dfs(prices, idx + 1, true, memo);
    return memo[idx][canBuy] = std::max(doNothing, sell);
  }
}

int maxProfit(std::vector<int> &prices) {
  std::vector<std::vector<int>> memo(prices.size(), std::vector<int>(2, -1));
  return dfs(prices, 0, true, memo);
}

int maxProfitTab(std::vector<int> &prices) {
  int n = prices.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, -1));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
    dp[i][1] = 0;
  }
  for (int idx = n - 1; idx >= 0; idx--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      int doNothing = dp[idx + 1][canBuy];
      if (canBuy) {
        int buy = -prices[idx] + dp[idx + 1][0];
        dp[idx][canBuy] = std::max(doNothing, buy);
      } else {
        int sell = prices[idx] + dp[idx + 1][1];
        dp[idx][canBuy] = std::max(doNothing, sell);
      }
    }
  }
  return dp[0][1];
}

int main(int argc, char *argv[]) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  std::cout << maxProfitTab(prices) << std::endl;
  return 0;
}
