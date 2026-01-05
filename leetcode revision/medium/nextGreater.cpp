#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> nextGreaterElements(std::vector<int> nums) {
    std::vector<int> res(nums.size(), 0);
    std::stack<int> st;
    for (int i = nums.size() * 2 - 1; i >= 0; i--) {
      while (!st.empty() && nums[i % nums.size()] >= st.top()) {
        st.pop();
      }
      if (i < nums.size()) {
        res[i] = st.empty() ? -1 : st.top();
      }
      st.push(nums[i % nums.size()]);
    }
    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {2, 10, 12, 1, 11};
  std::vector<int> res = s.nextGreaterElements(nums);
  for (int r : res) {
    std::cout << r << " ";
  }
  std::cout << std::endl;
  return 0;
}
