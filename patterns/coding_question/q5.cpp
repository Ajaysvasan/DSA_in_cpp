#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
  string str = "Java1223";
  unordered_set<char> seen;
  string res = "";

  for (char ch : str) {
    // If it's a duplicate, keep incrementing the character
    // until we find one that IS NOT in the set.
    while (seen.find(ch) != seen.end()) {
      ch++;
    }

    // Add the new valid character to the result and the set
    res += ch;
    seen.insert(ch);
  }

  // Expected output: Javb1234
  cout << res << "\n";

  return 0;
}
