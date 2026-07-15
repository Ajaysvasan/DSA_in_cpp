#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]) {
  string str = "a!uio";
  int left = 0;
  int right = str.size() - 1;
  while (left < right) {
    if (!isalnum(str[left])) {
      left++;
    } else if (!isalnum(str[right])) {
      right--;
    } else {
      swap(str[left], str[right]);
      left++;
      right--;
    }
  }
  cout << str;
  return 0;
}
