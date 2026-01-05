#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    // Your code goes here
    vector<int> res(indices.size(), 0);
    int i = 0;
    for (int idx : indices) {
      int count = 0;
      if (idx == arr.size() - 1) {
        break;
      }
      for (int j = idx + 1; j < arr.size(); j++) {
        if (arr[j] > arr[idx]) {
          count++;
        }
      }
      if (i < indices.size()) {
        res[i++] = count;
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = {3, 4, 2, 7, 5, 8, 10, 6};
  vector<int> indices = {0, 5};
  Solution s;
  vector<int> res = s.count_NGE(nums, indices);
  for (int r : res) {
    cout << r << " ";
  }
  cout << endl;
}
