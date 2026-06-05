#include <bits/stdc++.h>

int dfs(std::vector<int> &game_board, int k, std::vector<int> &dp, int idx) {
  if (idx >= game_board.size()) {
    return 0;
  }
  if (dp[idx] != -INT_MIN)
    return dp[idx];
  return dp[idx] = game_board[idx] + dfs(game_board, k, dp, idx + 1);
}

int maxKsteps(std::vector<int> &game_board, int k) {
  int max_value = INT_MIN;
  for (int i = 0; i < game_board.size(); i++) {
    std::vector<int> dp(game_board.size(), INT_MIN);
    int current_value = dfs(game_board, k, dp, i);
    int max_value = std::max(max_value, current_value);
  }
  return max_value;
}
