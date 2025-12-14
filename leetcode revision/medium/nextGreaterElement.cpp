#include <stack>
#include <vector>

std::vector<int> nextGreaterElement(std::vector<int> &nums) {
  std::vector<int> result(nums.size(), -1);
  std::stack<int> st;
  for (int i = 0; i < nums.size(); i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
      int temp = st.top();
      st.pop();
      result[temp] = nums[i];
    }
    st.push(i);
  }
  return result;
}
