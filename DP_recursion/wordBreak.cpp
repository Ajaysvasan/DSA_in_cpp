#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  bool dfs(string s, vector<string> &wordDict, int start, vector<bool> &dp) {
    if (start == s.size()) {
      return true;
    }
    if (dp[start]) {
      return false;
    }
    for (int i = start; i < s.size(); i++) {
      string word = s.substr(start, i - start + 1);
      if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
        if (dfs(s, wordDict, i + 1, dp)) {
          return dp[start] = true;
        }
      }
    }
    return dp[start] = false;
  }

  bool wordBreakMemo(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);
    return dfs(s, wordDict, 0, dp);
  }

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        string word = s.substr(i, j - i + 1);
        if (dict.count(word) && dp[j + 1]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[0];
  }
};
int main(int argc, char *argv[]) {
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  Solution sol;
  bool res = sol.wordBreak(s, wordDict);
  if (res) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
