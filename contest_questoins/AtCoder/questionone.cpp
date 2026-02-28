#include <iostream>
#include <string>
#include <vector>

using namespace std;

string modifiedString(string input) {
  if (input.empty())
    return "";

  int freq[256] = {0};
  int maxFreq = 0;

  for (char c : input) {
    freq[(unsigned char)c]++;
    if (freq[(unsigned char)c] > maxFreq) {
      maxFreq = freq[(unsigned char)c];
    }
  }

  string res = "";
  for (char c : input) {
    if (freq[(unsigned char)c] != maxFreq) {
      res += c;
    }
  }

  return res;
}

int main() {
  vector<string> testCases = {"mississippi", "atcoder"};
  for (const string &it : testCases) {
    cout << "Input: " << it << " -> Result: " << modifiedString(it) << endl;
  }
  return 0;
}
