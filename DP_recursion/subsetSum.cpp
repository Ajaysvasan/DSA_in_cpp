#include <algorithm>
#include <iostream>
#include <vector>

// version 1: using for loop in recursion
void dfs(std::vector<int> &arr, int target, int currentSum, int idx,
         int &count) {
  if (currentSum == target) {
    count++;
    return;
  }
  if (currentSum > target || idx >= arr.size()) {
    return;
  }
  for (int i = idx; i < arr.size(); i++) {
    dfs(arr, target, currentSum + arr[i], i + 1, count);
  }
}
// version 2: pick and not pick
void dfs_2(std::vector<int> &arr, int target, int currentSum, int idx,
           int &count) {
  if (currentSum == target) {
    count++;
    return;
  }
  if (currentSum > target || idx >= arr.size()) {
    return;
  }
  // pick
  dfs_2(arr, target, currentSum + arr[idx], idx + 1, count);
  dfs_2(arr, target, currentSum, idx + 1, count);
}

// version 3
bool dfs_3(std::vector<int> &arr, int target, int currentSum, int idx) {
  if (currentSum == target) {
    return true;
  }
  if (currentSum > target || idx >= arr.size()) {
    return false;
  }
  // pick
  bool left = dfs_3(arr, target, currentSum + arr[idx], idx + 1);
  bool right = dfs_3(arr, target, currentSum, idx + 1);
  return left || right;
}

bool isSubSetSum(std::vector<int> &arr, int target) {
  std::sort(arr.begin(), arr.end());
  int count = 0;
  dfs_3(arr, target, 0, 0);
  std::cout << count << std::endl;
  return count > 0;
}

int main() {
  std::vector<int> arr = {2, 3, 7, 8, 10};
  int target = 11;
  if (isSubSetSum(arr, target)) {
    std::cout << "Found a subset with given sum";
  } else {
    std::cout << "No subset with given sum";
  }
  return 0;
}
