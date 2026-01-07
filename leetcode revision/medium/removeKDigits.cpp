#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string nums, int k) {

    stack<char> st; // Stack

    for (int i = 0; i < nums.size(); i++) {

      char digit = nums[i];

      while (!st.empty() && k > 0 && st.top() > digit) {

        st.pop();
        k--;
      }

      st.push(digit);
    }

    while (!st.empty() && k > 0) {

      st.pop();
      k--;
    }

    if (st.empty())
      return "0";

    string res = "";

    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }

    while (res.size() > 0 && res.back() == '0') {

      res.pop_back();
    }

    reverse(res.begin(), res.end());

    if (res.empty())
      return "0";

    return res;
  }
};

int main() {
  string nums = "541892";
  int k = 2;

  Solution sol;

  string ans = sol.removeKdigits(nums, k);

  cout << "The smallest possible integer after removing k digits is: " << ans;

  return 0;
}
