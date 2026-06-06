#include <bits/stdc++.h>
int dfs(std::vector<int> &prices, int idx, int buy, int cap,
        std::vector<std::vector<std::vector<int>>> &dp) {
  if (idx == prices.size() || cap == 0)
    return 0;
  if (dp[idx][buy][cap] != -1)
    return dp[idx][buy][cap];
  if (buy) {
    return dp[idx][buy][cap] =
               std::max(dfs(prices, idx + 1, 0, cap, dp) - prices[idx],
                        dfs(prices, idx + 1, 1, cap, dp));
  }
  return dp[idx][buy][cap] =
             std::max(dfs(prices, idx + 1, 1, cap - 1, dp) + prices[idx],
                      dfs(prices, idx + 1, 0, cap, dp));
}

int bestTImeToBuyAndSellStocks(std::vector<int> &prices) {
  std::vector<std::vector<std::vector<int>>> dp(
      prices.size(), std::vector<std::vector<int>>(2, std::vector<int>(3, -1)));
  return dfs(prices, 0, 1, 2, dp);
}

int bestTimeToBuyAndSellStocksTab(std::vector<int> &prices) {
  int n = prices.size();
  if (n == 0)
    return 0;

  // STEP 1: Size & Initialize
  // Sized n + 1 to handle the 'idx == n' base case naturally.
  // Initialized entirely to 0 to handle both 'idx == n' and 'cap == 0' base
  // cases.
  std::vector<std::vector<std::vector<int>>> dp(
      n + 1, std::vector<std::vector<int>>(2, std::vector<int>(3, 0)));

  // STEP 2: Loop Direction
  // idx moves backwards (n-1 down to 0)
  for (int idx = n - 1; idx >= 0; idx--) {
    // buy explores both states (0 and 1)
    for (int buy = 0; buy <= 1; buy++) {
      // cap explores valid remaining transactions (1 and 2).
      // cap = 0 is skipped because it's effectively our 0-initialized base
      // case.
      for (int cap = 1; cap <= 2; cap++) {

        // STEP 3: Copy/Paste State Transitions
        if (buy) {
          dp[idx][buy][cap] =
              std::max(dp[idx + 1][0][cap] - prices[idx], dp[idx + 1][1][cap]);
        } else {
          dp[idx][buy][cap] = std::max(dp[idx + 1][1][cap - 1] + prices[idx],
                                       dp[idx + 1][0][cap]);
        }
      }
    }
  }

  // The final answer mirrors the initial top-down call: Day 0, allowed to buy,
  // 2 transactions left.
  return dp[0][1][2];
}

int main(int argc, char *argv[]) {
  std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  std::cout << bestTImeToBuyAndSellStocks(prices);
  return 0;
}
