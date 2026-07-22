#include <iostream>
#include <vector>

using namespace std;
// 16. Assume there exists infinite grid, you’re given initial position x, y.
// Inputs will be movements either L or R or U or D. After n inputs, you need to
// give the current position. •	Input: •	4 5 //initial position x, y •
// 9 //number of movements •	U L R R D D U L R //7 movements •	Output:
// 5 5
int main(int argc, char *argv[]) {
  int row, col;
  cin >> row >> col;
  int n;
  cin >> n;
  vector<char> movements(n);
  for (int i = 0; i < n; i++) {
    cin >> movements[i];
  }
  for (char movement : movements) {
    switch (movement) {
    case 'R':
      row++;
      break;
    case 'L':
      row--;
      break;
    case 'D':
      col--;
      break;
    case 'U':
      col++;
      break;
    }
  }
  cout << row << " " << col;
  return 0;
}
