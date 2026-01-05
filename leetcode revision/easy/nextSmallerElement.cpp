#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> nextSmallerElements(const std::vector<int> &arr) {
    // Your code goes here
    std::vector<int> res(arr.size(), -1);
    std::stack<int> st;
    for (int i = arr.size() - 1; i <= 0; i--) {
      while (!st.empty() && arr[i] <= st.top()) {
        st.pop();
      }
      if (!st.empty()) {
        res[i] = st.top();
      }
      st.push(arr[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {4, 8, 5, 2, 25};
  std::vector<int> res = s.nextSmallerElements(nums);
  for (int r : res) {
    std::cout << r << " ";
  }
  std::cout << "\n";
  return 0;
}
