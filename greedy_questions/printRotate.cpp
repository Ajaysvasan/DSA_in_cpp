#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, char> mapping = {
    {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

bool validString(std::string s) {
  std::string rotated = "";
  for (int i = 0; i < s.size(); i++) {
    if (mapping.find(s[i]) == mapping.end())
      return false;
    rotated = mapping[s[i]] + rotated;
  }
  return s == rotated;
}

void dfs(int n, std::string current, std::vector<std::string> &result) {
  if (current.length() == n) {
    result.push_back(current);
    return;
  }

  for (auto it : mapping) {
    if (it.first == '0' && current.empty() && n > 1) {
      continue;
    }

    dfs(n, current + it.first, result);
  }
}

int main(int argc, char *argv[]) {
  int n;
  std::vector<std::string> result;
  if (!(std::cin >> n))
    return 0;

  dfs(n, "", result);
  std::sort(result.begin(), result.end());

  for (std::string s : result) {
    if (validString(s)) {
      std::cout << s << " ";
    }
  }

  return 0;
}
