#include <bits/stdc++.h>

int knapsack(std::vector<int> wt, std::vector<int> val, int w, int n,
             std::vector<std::vector<int>> &memo) {
  if (n == 0 || w == 0) {
    return 0;
  }
  if (memo[n][w] != -1)
    return memo[n][w];
  if (wt[n - 1] > w) {
    return memo[n][w] = knapsack(wt, val, w, n - 1, memo);
  } else {
    return memo[n][w] = std::max(
               val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, memo),
               knapsack(wt, val, w, n - 1, memo));
  }
}

int main(int argc, char *argv[]) {
  int n, w;
  std::cin >> n >> w;
  std::vector<int> wt(n), val(n);
  for (int i = 0; i < n; i++) {
    std::cin >> wt[i] >> val[i];
  }
  return 0;
}
