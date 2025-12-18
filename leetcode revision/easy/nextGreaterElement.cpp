#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> nextGreater;
  vector<int> res;
  stack<int> st;
  for (int i = 0; i < nums2.size(); i++) {
    while (!st.empty() && nums2[i] > nums2[st.top()]) {
      nextGreater[nums2[st.top()]] = nums2[i];
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    nextGreater[nums2[st.top()]] = -1;
    st.pop();
  }
  for (int num : nums1) {
    res.push_back(nextGreater[num]);
  }
  return res;
}
