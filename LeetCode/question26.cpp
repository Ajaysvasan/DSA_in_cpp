#include <iostream>
#include <stack>
#include <string.h>
bool isValid(std::string str) {
  std::stack<char> stk;
  for (char ch : str) {
    if (ch == '{' || ch == '(' || ch == '[') {
      stk.push(ch);
    } else if (ch == '}' || ch == ')' || ch == ']') {
      if (stk.empty())
        return false;
      char temp = stk.top();
      if ((temp == '{' && ch == '}') || (temp == '(' && ch == ')') ||
          (temp == '[' && ch == ']')) {
        stk.pop();
      } else {
        return false;
      }
    }
  }
  return stk.empty();
}

int main() {
  std::string str = "(])";
  std::cout << isValid(str);
  return 0;
}
