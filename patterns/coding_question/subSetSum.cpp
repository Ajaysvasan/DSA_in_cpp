#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &nums, int target, int idx,
         vector<vector<int>> &combinations, vector<int> &combination) {

  // 1. Success condition checked FIRST
  if (target == 0) {
    combinations.push_back(combination);
    return; // We reached the sum, no need to add more numbers
  }

  // 2. Failure conditions checked SECOND
  if (target < 0 || idx == nums.size()) {
    return;
  }

  for (int i = idx; i < nums.size(); i++) {
    combination.push_back(nums[i]);
    // Move to i + 1 so we don't reuse the same element
    dfs(nums, target - nums[i], i + 1, combinations, combination);
    combination.pop_back(); // Backtrack
  }
}

int main(int argc, char *argv[]) {
  // Better input handling: Read number of elements first
  int size;
  cout << "Enter number of elements: ";
  cin >> size;

  vector<int> nums(size);
  cout << "Enter elements: ";
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }

  int n;
  cout << "Enter target sum N: ";
  cin >> n;

  vector<vector<int>> combinations;
  vector<int> combination;

  dfs(nums, n, 0, combinations, combination);

  cout << "Output:\n";
  for (auto &row : combinations) {
    cout << "{";
    for (int i = 0; i < row.size(); i++) {
      cout << row[i] << (i == row.size() - 1 ? "" : ", ");
    }
    cout << "}\n";
  }

  return 0;
}
