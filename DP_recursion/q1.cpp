#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &arr, int high, int low, int target) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      return binarySearch(arr, mid - 1, low, target);
    } else {
      return binarySearch(arr, high, mid + 1, target);
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};
  int target = 0;
  std::cout << binarySearch(arr, arr.size() - 1, 0, target);
  return 0;
}
