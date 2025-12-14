#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> &prices) {
  int n = prices.size();
  vector<int> span(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && prices[st.top()] <= prices[i]) {
      st.pop();
    }

    span[i] = st.empty() ? (i + 1) : (i - st.top());

    st.push(i);
  }

  return span;
}
