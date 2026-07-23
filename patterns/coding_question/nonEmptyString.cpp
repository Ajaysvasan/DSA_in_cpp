#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string &str) {
  if (str.empty()) {
    return false;
  }

  std::string doubled = str + str;

  return doubled.find(str, 1) < str.length();
}

int main(int argc, char *argv[]) {
  std::string str;
  if (std::cin >> str) {
    if (repeatedSubstringPattern(str)) {
      std::cout << "true\n";
    } else {
      std::cout << "false\n";
    }
  }
  return 0;
}
