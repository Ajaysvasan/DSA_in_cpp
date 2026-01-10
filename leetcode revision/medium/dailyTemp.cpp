#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    std::vector<int> res(temperatures.size(), 0);
    std::stack<int> st;
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        int idx = st.top();
        st.pop();
        res[idx] = i - idx;
      }
      st.push(i);
    }
    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
  std::cout << "The solution for this problem is: \n";
  std::vector<int> res = s.dailyTemperatures(temps);
  std::vector<int> actual_output = {1, 1, 4, 2, 1, 1, 0, 0};
  bool flag = true;
  for (int i = 0; i < res.size(); i++) {
    if (actual_output[i] != res[i]) {
      flag = false;
    }
  }
  if (flag) {
    std::cout << "\n The code is correct";
  } else {
    std::cout << "The code is wrong";
  }
  return 0;
}
