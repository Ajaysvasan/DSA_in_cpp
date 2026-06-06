#include <bits/stdc++.h>

bool isPalindrome(int i, int j, std::string &s) {
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int frontPartition(std::string &s1, int idx, std::vector<int> &dp) {
  if (idx == s1.size())
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int min_value = INT_MAX;
  for (int i = idx; i < s1.size(); i++) {
    if (isPalindrome(idx, i, s1)) {
      int cost = 1 + frontPartition(s1, i + 1, dp);
      min_value = std::min(min_value, cost);
    }
  }
  return dp[idx] = min_value;
}

int palindromePartition2(std::string &s1) {
  std::vector<int> dp(s1.size(), -1);
  return frontPartition(s1, 0, dp) - 1;
}

int palindromePartition2Tab(std::string &s) {
  std::vector<int> dp(s.size() + 1, 0);
  for (int i = s.size() - 1; i >= 0; i--) {
    int min_value = INT_MAX;
    for (int j = i; j < s.size(); j++) {
      if (isPalindrome(i, j, s)) {
        int cost = 1 + dp[j + 1];
        min_value = std::min(min_value, cost);
      }
    }
    dp[i] = min_value;
  }
  return dp[0] - 1;
}

int main(int argc, char *argv[]) {
  std::string s = "aab";
  std::cout << palindromePartition2Tab(s);
  return 0;
}
