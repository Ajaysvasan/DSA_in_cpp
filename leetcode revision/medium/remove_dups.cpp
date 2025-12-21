#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);
    vector<bool> used(26, false);
    stack<char> st;

    // Step 1: frequency count
    for (char ch : s) {
      freq[ch - 'a']++;
    }

    // Step 2: process characters
    for (char ch : s) {
      int idx = ch - 'a';
      freq[idx]--;

      // already in stack → skip
      if (used[idx])
        continue;

      // maintain lexicographical order
      while (!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0) {
        used[st.top() - 'a'] = false;
        st.pop();
      }

      st.push(ch);
      used[idx] = true;
    }

    // Step 3: build result
    string result;
    while (!st.empty()) {
      result.push_back(st.top());
      st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
  }
};

int main() {
  string s = "bcabc";
  Solution solution;
  cout << solution.removeDuplicateLetters(s);
  return 0;
}
