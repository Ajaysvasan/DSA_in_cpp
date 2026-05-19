#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<int> &arr, std::vector<std::vector<int>> &res,
         std::vector<int> &combination, int target, int idx, int currentSum) {
  if (idx >= arr.size() || currentSum > target) {
    return;
  }
  if (currentSum == target) {
    res.push_back(combination);
    return;
  }
  combination.push_back(arr[idx]);
  dfs(arr, res, combination, target, idx, currentSum + arr[idx]);
  combination.pop_back();
  dfs(arr, res, combination, target, idx + 1, currentSum);
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &arr,
                                             int target) {
  std::sort(arr.begin(), arr.end());
  std::vector<int> combination;
  std::vector<std::vector<int>> res;
  dfs(arr, res, combination, target, 0, 0);
  return res;
}
int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 3, 6, 7};

  std::vector<std::vector<int>> res = combinationSum(arr, 7);
  for (std::vector<int> &row : res) {
    for (int value : row) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
}
