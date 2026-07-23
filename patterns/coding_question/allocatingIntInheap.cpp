#include <iostream>

int main() {
  int *raw_heap_array = new int[5];

  for (int i = 0; i < 5; ++i) {
    raw_heap_array[i] = (i + 1) * 10;
    std::cout << "Value at index " << i << ": " << raw_heap_array[i] << "\n";
  }
  delete[] raw_heap_array;

  raw_heap_array = nullptr;

  return 0;
}
