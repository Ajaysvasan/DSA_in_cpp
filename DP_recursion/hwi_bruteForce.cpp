#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*Given two graphs G1 and G2 of size m x n
 * The goal is to reach the goal state that is from (0 , 0 ) to (m - 1 , n-1)
 * state I am allowed to traverse in all four directions The goal is to reach
 * the end state with maximum profit I am allowed to jump between G1 and G2 but
 * the jump cost a penalty of 5 after subtracting I have to choose the one that
 * gives me the max value
 *
 * Input
 * G1 (m , n)
 * G2 (m , n)
 *
 * Output :
 * Max profit*/

int helper(vector<vector<int>> &G1, vector<vector<int>> &G2, int row, int col,
           int maxSum, bool &isG1) {
  if (row == 0 && col == 0) {
    if (G1[row][col] < G2[row][col]) {
      maxSum += G2[row][col];
      isG1 = false;
    } else {
      maxSum += G1[row][col];
    }
  } else if (G1[row][col] < G2[row][col] && !isG1) {
    // I can take the value without penalty since it is already at G2
    maxSum += G2[row][col];
  } else if (G1[row][col] < G2[row][col] && isG1) {
    // Need to apply penalty
    int p_value = G2[row][col] - 5;
    // check if the p_vlaue > G2 value
    if (p_value > G1[row][col]) {
      maxSum += p_value;
      isG1 = false;
    } else {
      // take the value of G1
      maxSum += G1[row][col];
    }
  } else if (G2[row][col] < G1[row][col] && isG1) {
    // No penalty needed
    maxSum += G1[row][col];
  } else if (G2[row][col] < G1[row][col] && !isG1) {
    // penalty needed
    int p_value = G1[row][col] - 5;
    if (p_value > G2[row][col]) {
      maxSum += p_value;
      isG1 = true;
    } else {
      maxSum += G2[row][col];
    }
  } else if (G1[row][col] == G2[row][col] && isG1) {
    maxSum += G1[row][col];
  } else {
    maxSum += G2[row][col];
  }
  return maxSum;
}

int dfs(vector<vector<int>> &G1, vector<vector<int>> &G2, int m, int n, int row,
        int col, int maxSum, bool isG1, vector<vector<bool>> &visited) {
  if (row == m - 1 && col == n - 1) {

    return helper(G1, G2, row, col, maxSum, isG1);
  }
  if (row < 0 || col < 0 || row >= m || col >= n)
    return INT_MIN;

  if (visited[row][col])
    return INT_MIN;
  visited[row][col] = true;

  maxSum = helper(G1, G2, row, col, maxSum, isG1);

  int right = dfs(G1, G2, m, n, row, col + 1, maxSum, isG1, visited);

  int left = dfs(G1, G2, m, n, row, col - 1, maxSum, isG1, visited);
  int up = dfs(G1, G2, m, n, row - 1, col, maxSum, isG1, visited);
  int down = dfs(G1, G2, m, n, row + 1, col, maxSum, isG1, visited);
  visited[row][col] = false;
  return max(max(left, right), max(up, down));
}

int maxProfit(vector<vector<int>> G1, vector<vector<int>> G2, int m, int n) {
  bool isG1 = true;
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  return dfs(G1, G2, m, n, 0, 0, 0, isG1, visited);
}

/*Given two graphs G1 and G2 of size m x n
 * The goal is to reach the goal state that is from (0 , 0 ) to (m - 1 , n-1)
 * state I am allowed to traverse in all two directions right / down. The goal
 * is to reach the end state with maximum profit I am allowed to jump between G1
 * and G2 but the jump cost a penalty of 5 after subtracting I have to choose
 * the one that gives me the max value
 *
 * Input
 * G1 (m , n)
 * G2 (m , n)
 *
 * Output :
 * Max profit*/

int dfsRightDown(vector<vector<int>> &G1, vector<vector<int>> &G2, int m, int n,
                 int row, int col, int maxSum, bool isG1,
                 vector<vector<vector<int>>> &dp) {
  if (row == m - 1 && col == n - 1) {
    return helper(G1, G2, row, col, maxSum, isG1);
  }
  if (row >= m || col >= n || row < 0 || col < 0) {
    return INT_MIN;
  }

  if (dp[row][col][isG1 ? 0 : 1] != -1)
    return dp[row][col][isG1 ? 0 : 1];

  maxSum = helper(G1, G2, row, col, maxSum, isG1);
  return dp[row][col][isG1 ? 0 : 1] =
             max(dfsRightDown(G1, G2, m, n, row + 1, col, maxSum, isG1, dp),
                 dfsRightDown(G1, G2, m, n, row, col + 1, maxSum, isG1, dp));
}

int maxProfitMemo(vector<vector<int>> G1, vector<vector<int>> G2, int m,
                  int n) {
  bool isG1 = true;
  // 1 -> graph one G2  , 0 -> Graph 1 G1
  // dp[row][col][graph]
  vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
  return dfsRightDown(G1, G2, m, n, 0, 0, 0, isG1, dp);
}

int main(int argc, char *argv[]) {

  vector<vector<int>> G1 = {{1, 8, 3}, {4, 7, 5}, {7, 5, 9}};
  vector<vector<int>> G2 = {{3, 4, 7}, {5, 6, 4}, {8, 10, 7}};
  cout << maxProfitMemo(G1, G2, G1.size(), G1[0].size()) << std::endl;

  vector<vector<int>> G3 = {{10, 4, 0}};
  vector<vector<int>> G4 = {{0, 6, 100}};
  cout << maxProfitMemo(G3, G4, G3.size(), G3[0].size()) << std::endl;
}
