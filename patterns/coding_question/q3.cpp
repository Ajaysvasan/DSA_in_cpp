#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<int>> screen = {
      {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0},
      {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1},
  };
  int x = 4, y = 4, new_color = 3;
  int prev_pixel_value = screen[x][y];

  if (prev_pixel_value == new_color)
    return 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  int dr[] = {1, -1, 0, 0};

  int dc[] = {0, 0, 1, -1};
  while (!q.empty()) {
    int curr_row = q.front().first;
    int curr_col = q.front().second;
    q.pop();
    if (screen[curr_row][curr_col] == prev_pixel_value) {
      screen[curr_row][curr_col] = new_color;
    }
    for (int i = 0; i < 4; i++) {
      int new_row = curr_row + dr[i];
      int new_col = curr_col + dc[i];
      if (new_row >= 0 && new_row < screen.size() && new_col >= 0 &&
          new_col < screen[0].size() &&
          screen[new_row][new_col] == prev_pixel_value) {
        q.push({new_row, new_col});
      }
    }
  }
  for (vector<int> &s : screen) {
    for (int pixel : s) {
      cout << pixel << " ";
    }
    cout << "\n";
  }
  return 0;
}
