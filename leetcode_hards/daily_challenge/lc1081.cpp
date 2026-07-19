#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string smallestSubsequence(string s) {
    vector<int> charFrequency(26);
    for (char ch : s) {
      charFrequency[ch - 'a']++;
    }
    stack<int> st;
    vector<bool> used(26, false);
    for (char ch : s) {
      charFrequency[ch - 'a']--;
      if (used[ch - 'a'])
        continue;
      while (!st.empty() && st.top() > ch &&
             charFrequency[st.top() - 'a'] > 0) {
        used[st.top() - 'a'] = false;
        st.pop();
      }
      st.push(ch);
      used[ch - 'a'] = true;
    }
    string res = "";
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
