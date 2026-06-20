#include <iostream>

int main(int argc, char *argv[]) {
  int x, y;
  std::cin >> x >> y;
  // ratio 16 to 9
  if (x % 16 == 0 && y % 9 == 0) {
    std::cout << "Yes";
    return 0;
  }
  std::cout << "No";
  return 0;
}
