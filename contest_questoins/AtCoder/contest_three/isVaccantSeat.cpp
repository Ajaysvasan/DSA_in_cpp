#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> trains;
  int n;
  // Col for which I want the seat
  char col;
  std::cin >> n >> col;
  for (int i = 0; i < n; i++) {
    std::vector<char> train;
    for (int j = 0; j < 5; j++) {
      char seat;
      std::cin >> seat;
      train.push_back(seat);
    }
    trains.push_back(train);
  }
  bool isVaccantSeatFound = false;
  for (int i = 0; i < n; i++) {
    if (trains[i][col - 'A'] == 'o') {
      isVaccantSeatFound = true;
      break;
    }
  }
  if (isVaccantSeatFound) {
    std::cout << "Yes";
    return 0;
  }
  std::cout << "No";
  return 0;
}
