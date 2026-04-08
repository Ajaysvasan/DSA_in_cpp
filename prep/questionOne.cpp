#include <iostream>
using namespace std;

class Patterns {
  int n;

public:
  Patterns(int n) { this->n = n; }
  void squareHallowPattern() {
    cout << "Printing the square hallow pattern:" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
  void numberTrianglePattern() {
    for (int i = 1; i <= n; i++) {
      // to get the space
      for (int j = 1; j <= n - i; j++) {
        cout << " ";
      }
      for (int j = 1; j <= i; j++) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  void numberIncreasingPattern() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
  void numberDecreasingPattern() {
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
  void numberChangingPattern() {
    int val = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << val++ << " ";
      }
      cout << endl;
    }
  }
  void zeroOnePattern() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if ((i + j) % 2 != 1) {
          cout << 1 << " ";
        } else {
          cout << 0 << " ";
        }
      }
      cout << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  Patterns p(5);
  p.zeroOnePattern();
  return 0;
}
