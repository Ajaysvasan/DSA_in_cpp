#include <iostream>
int guess(int num);
int guessNumber(int n) {
  int low = 0, high = n;
  int picked_num = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int guessed_number = guess(mid);
    if (guessed_number == 0) {
      picked_num = mid;
      break;
    } else if (guessed_number == -1) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    return picked_num;
  }
}
int main() {
  std::cout << guessNumber(10);
  return 0;
}

int guess(int num) {
  // this is just an placeholder
  return 1;
}
