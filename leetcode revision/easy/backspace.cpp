#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool backspaceCompare(string s, string t) {
  string res1 = "";
  string res2 = "";
  stack<char> st;
  for (char ch : s) {
    if (st.empty() && ch != '#') {
      st.push(ch);
    } else if (ch == '#' && !st.empty()) {
      st.pop();
    } else if (ch != '#') {
      st.push(ch);
    }
  }
  while (!st.empty()) {
    res1 += st.top();
    st.pop();
  }

  for (char ch : t) {
    if (st.empty() && ch != '#') {
      st.push(ch);
    } else if (ch == '#' && !st.empty()) {
      st.pop();
    } else if (ch != '#') {
      st.push(ch);
    }
  }
  while (!st.empty()) {
    res2 += st.top();
    st.pop();
  }
  return (res1 == res2) ? true : false;
}
int main() {
  cout << backspaceCompare("ab#c", "ad#c");
  return 0;
}
