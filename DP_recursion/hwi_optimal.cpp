#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int PENALTY = 5;
const int NEG_INF = -1000000000;

int dfs(vector<vector<int>> &G1, vector<vector<int>> &G2, int row, int col,
        int graph, vector<vector<vector<int>>> &memo) {

  int m = G1.size();
  int n = G1[0].size();

  if (row >= m || col >= n)
    return NEG_INF;

  if (memo[row][col][graph] != INT_MIN)
    return memo[row][col][graph];

  // Destination cell
  if (row == m - 1 && col == n - 1) {

    if (graph == 0) {
      int stay = G1[row][col];
      int sw = G2[row][col] - PENALTY;
      return memo[row][col][graph] = max(stay, sw);
    } else {
      int stay = G2[row][col];
      int sw = G1[row][col] - PENALTY;
      return memo[row][col][graph] = max(stay, sw);
    }
  }

  int answer;

  if (graph == 0) {

    // Stay on G1
    int stay = G1[row][col] + max(dfs(G1, G2, row + 1, col, 0, memo),
                                  dfs(G1, G2, row, col + 1, 0, memo));

    // Switch to G2
    int sw = (G2[row][col] - PENALTY) + max(dfs(G1, G2, row + 1, col, 1, memo),
                                            dfs(G1, G2, row, col + 1, 1, memo));

    answer = max(stay, sw);
  } else {

    // Stay on G2
    int stay = G2[row][col] + max(dfs(G1, G2, row + 1, col, 1, memo),
                                  dfs(G1, G2, row, col + 1, 1, memo));

    // Switch to G1
    int sw = (G1[row][col] - PENALTY) + max(dfs(G1, G2, row + 1, col, 0, memo),
                                            dfs(G1, G2, row, col + 1, 0, memo));

    answer = max(stay, sw);
  }

  return memo[row][col][graph] = answer;
}

int maxProfit(vector<vector<int>> &G1, vector<vector<int>> &G2) {

  int m = G1.size();
  int n = G1[0].size();

  vector<vector<vector<int>>> memo(
      m, vector<vector<int>>(n, vector<int>(2, INT_MIN)));

  // Problem states we may start in either graph
  return max(dfs(G1, G2, 0, 0, 0, memo), dfs(G1, G2, 0, 0, 1, memo));
}

int main() {

  vector<vector<int>> G1 = {{1, 8, 3}, {4, 7, 5}, {7, 5, 9}};

  vector<vector<int>> G2 = {{3, 4, 7}, {5, 6, 4}, {8, 10, 7}};

  cout << maxProfit(G1, G2) << "\n";

  vector<vector<int>> G3 = {{10, 4, 0}};

  vector<vector<int>> G4 = {{0, 6, 100}};

  cout << maxProfit(G3, G4) << "\n";
}
