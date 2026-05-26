#include <iostream>
#include <vector>

int dfs(std::vector<int> &arr, int target, int index,
        std::vector<std::vector<int>> &memo) {
  if (target == 0)
    return 1;
  if (index >= arr.size() || target < 0)
    return 0;
  if (memo[index][target] != -1)
    return memo[index][target];

  int include = dfs(arr, target - arr[index], index + 1, memo);
  int exclude = dfs(arr, target, index + 1, memo);

  memo[index][target] = include || exclude;
  return memo[index][target];
}

bool subsetSum(std::vector<int> &arr, int target) {
  std::vector<std::vector<int>> memo(arr.size(),
                                     std::vector<int>(target + 1, -1));
  return dfs(arr, target, 0, memo);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {3, 34, 4, 12, 5, 2};
  int target = 9;
  if (subsetSum(arr, target)) {
    std::cout << "Subset with given sum exists." << std::endl;
  } else {
    std::cout << "Subset with given sum does not exist." << std::endl;
  }
  return 0;
}
