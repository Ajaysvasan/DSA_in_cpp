#include <algorithm>
#include <iostream>
#include <vector>

int coinChange(std::vector<int> &coins, int amount) {
  if (amount == 0)
    return 0;
  if (amount < 0)
    return -1;
  int INF = amount + 1;
  std::vector<std::vector<int>> dp(coins.size() + 1,
                                   std::vector<int>(amount + 1, INF));
  for (int i = 0; i <= coins.size(); i++)
    dp[i][0] = 0;
  for (int i = 1; i <= coins.size(); i++) {
    for (int j = 1; j <= amount; j++) {
      if (coins[i - 1] <= j) {
        dp[i][j] = std::min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[coins.size()][amount] == INF ? -1 : dp[coins.size()][amount];
}

int main(int argc, char *argv[]) {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  std::cout << coinChange(coins, amount) << std::endl;
  return 0;
}
