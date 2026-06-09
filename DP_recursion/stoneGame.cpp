#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  int dfs(vector<int> &piles, int left, int right, vector<vector<int>> &dp) {
    if (left > right) {
      return 0;
    }
    if (dp[left][right] != -1) {
      return dp[left][right];
    }
    int take_left = piles[left] - dfs(piles, left + 1, right, dp);

    int take_right = piles[right] - dfs(piles, left, right - 1, dp);
    return dp[left][right] = max(take_left, take_right);
  }

  bool stoneGameMemo(vector<int> &piles) {
    vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
    return dfs(piles, 0, piles.size() - 1, dp) > 0;
  }

public:
  bool stoneGame(vector<int> &piles) {
    vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
    for (int i = 0; i < piles.size(); i++) {
      dp[i][i] = piles[i];
    }
    for (int i = piles.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < piles.size(); j++) {
        int take_left = piles[j] - dp[i + 1][j];
        int take_right = piles[j] - dp[i][j - 1];
        dp[i][j] = max(take_left, take_right);
      }
    }
    return dp[0][piles.size() - 1];
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> piles = {5, 3, 4, 5};
  Solution sol;
  cout << sol.stoneGame(piles);
  return 0;
}
