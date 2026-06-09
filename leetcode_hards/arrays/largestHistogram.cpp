#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int max_area = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int temp = st.top();
        st.pop();
        int left = i;
        int right = st.empty() ? -1 : st.top();
        int width = left - right + 1;
        max_area = max(max_area, (heights[temp] * width));
      }
      st.push(i);
    }
    return max_area;
  }
};
