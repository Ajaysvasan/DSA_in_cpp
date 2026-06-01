#include <bits/stdc++.h>

int dfs(std::vector<int> &energy, int idx, std::vector<int> &memo) {
  if (idx >= energy.size()) {
    return 0;
  }
  if (memo[idx] != -1)
    return memo[idx];
  return memo[idx] = energy[idx] + std::max(+dfs(energy, idx + 1, memo),
                                            dfs(energy, idx + 2, memo));
}

int maxEnergyPath(std::vector<int> &energy) {
  std::vector<int> memo(energy.size(), -1);
  int maxValue = dfs(energy, 0, memo);
  for (int value : memo) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
  return maxValue;
}

int maxEnergyPathTab(std::vector<int> &energy) {
  int n = energy.size();
  std::vector<int> dp(energy.size() + 2, 0);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = energy[i] + std::max(dp[i + 2], dp[i + 1]);
  }
  return dp[0];
}
int main(int argc, char *argv[]) {
  std::vector<int> energy = {3, -2, 5, -1, 4};
  std::cout << maxEnergyPathTab(energy);
  return 0;
}
