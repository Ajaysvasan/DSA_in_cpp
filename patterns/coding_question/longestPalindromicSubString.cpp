#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string str;
  std::cin >> str;
  if (str.size() == 1) {
    std::cout << str;
    return 0;
  }
  int maxLen = 1;
  // Expand around centre
  //  left-- i right++
  // babad
  std::string res;
  for (int i = 0; i < str.size(); i++) {
    int left = i, right = i;
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
      if (right - left + 1 > maxLen) {
        res = str.substr(left, right);
      }
      left--;
      right++;
    }
    left = i, right = i + 1;
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
      if (right - left + 1 > maxLen) {
        res = str.substr(left, right);
      }
      left--;
      right++;
    }
  }
  std::cout << res;
  return 0;
}
