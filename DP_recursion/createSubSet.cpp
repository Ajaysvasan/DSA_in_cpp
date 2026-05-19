#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &arr, vector<int> &combination, vector<vector<int>> &res,
         int idx) {
  if (idx == arr.size()) {
    res.push_back(combination);
    return;
  }
  combination.push_back(arr[idx]);
  dfs(arr, combination, res, idx + 1);
  combination.pop_back();
  dfs(arr, combination, res, idx + 1);
}

vector<vector<int>> SubSet(vector<int> &arr) {
  vector<vector<int>> res;
  vector<int> combination;
  dfs(arr, combination, res, 0);
  return res;
}
int main() {
  vector<int> arr = {1, 2, 3};

  vector<vector<int>> res = SubSet(arr);
  sort(res.begin(), res.end());
  for (vector<int> &row : res) {
    for (int value : row) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
}
