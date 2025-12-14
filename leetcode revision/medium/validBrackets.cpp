#include <stack>
#include <string>
bool valid(std::string &s) {
  std::stack<char> st;

  for (char ch : s) {
    if (ch == '(' || ch == '[' || ch == '{') {
      st.push(ch);
    } else {
      if (st.empty())
        return false;

      if ((ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') ||
          (ch == ']' && st.top() != '[')) {
        return false;
      }

      st.pop();
    }
  }

  return st.empty();
}
