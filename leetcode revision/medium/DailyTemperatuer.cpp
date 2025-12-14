#include <stack>
#include <vector>

std::vector<int> dailyTem(std::vector<int> &temps) {
  std::vector<int> result(temps.size(), 0);
  std::stack<int> st;
  for (int i = 0; i < temps.size(); i++) {
    while (!st.empty() && temps[i] > temps[st.top()]) {
      int temp = st.top();
      st.pop();
      result[temp] = i - temp;
    }
    st.push(i);
  }
  return result;
}
