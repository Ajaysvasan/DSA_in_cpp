#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  int MOD = 1e9 + 7;

  pair<int, int> dfs(int r, int c, vector<string> &board,
                     vector<vector<pair<int, int>>> &memo) {
    if (r < 0 || c < 0 || board[r][c] == 'X') {
      return {0, 0};
    }

    if (r == 0 && c == 0) {
      return {0, 1}; // Score is 0, 1 way to get here
    }

    if (memo[r][c].first != -1) {
      return memo[r][c];
    }

    pair<int, int> up = dfs(r - 1, c, board, memo);
    pair<int, int> left = dfs(r, c - 1, board, memo);
    pair<int, int> diag = dfs(r - 1, c - 1, board, memo);

    int max_child_score = max({up.first, left.first, diag.first});
    int paths = 0;

    if (up.first == max_child_score)
      paths = (paths + up.second) % MOD;
    if (left.first == max_child_score)
      paths = (paths + left.second) % MOD;
    if (diag.first == max_child_score)
      paths = (paths + diag.second) % MOD;

    int current_score = 0;

    if (paths > 0) {
      if (board[r][c] != 'S') {
        current_score = max_child_score + (board[r][c] - '0');
      } else {
        current_score = max_child_score; // 'S' has no numeric value
      }
    }

    return memo[r][c] = {current_score, paths};
  }

public:
  vector<int> pathsWithMaxScore(vector<string> &board) {
    int n = board.size();
    vector<vector<pair<int, int>>> memo(n, vector<pair<int, int>>(n, {-1, -1}));

    pair<int, int> result = dfs(n - 1, n - 1, board, memo);

    return {result.first, result.second};
  }
};

ostream &operator<<(ostream &COUT, const vector<int> &values) {
  COUT << "{";
  for (int i = 0; i < values.size(); i++) {
    COUT << values[i] << (i < values.size() - 1 ? " , " : "");
  }
  COUT << "}";
  return COUT;
}

int main(int argc, char *argv[]) {
  Solution sol;
  vector<string> board = {"E23", "2X2", "12S"};

  cout << "Program output : " << sol.pathsWithMaxScore(board) << "\n";
  cout << "Actual output  : {7 , 1}\n";
  return 0;
}
