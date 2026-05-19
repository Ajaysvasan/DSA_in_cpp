#include <iostream>
#include <vector>

void backtrack(std::vector<int> &arr, int start,
               std::vector<std::vector<int>> &res) {
  if (start == arr.size()) {
    res.push_back(arr);
    return;
  }

  for (int i = start; i < arr.size(); i++) {
    std::swap(arr[start], arr[i]);

    backtrack(arr, start + 1, res);

    std::swap(arr[start], arr[i]);
  }
}

std::vector<std::vector<int>> permute(std::vector<int> &arr) {
  std::vector<std::vector<int>> res;
  backtrack(arr, 0, res);
  return res;
}
int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3};
  std::vector<std::vector<int>> res = permute(arr);
  for (std::vector<int> &row : res) {
    for (int value : row) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
