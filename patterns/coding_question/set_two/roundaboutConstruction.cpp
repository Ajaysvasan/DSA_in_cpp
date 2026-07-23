#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string rearrange(string s) {
  unordered_map<char, int> freq;
  vector<char> order;

  // Record first occurrence order and frequencies
  for (char ch : s) {
    if (freq.find(ch) == freq.end())
      order.push_back(ch);
    freq[ch]++;
  }

  string ans;

  while (true) {
    bool added = false;

    for (char ch : order) {
      if (freq[ch] > 0) {
        ans += ch;
        freq[ch]--;
        added = true;
      }
    }

    if (!added)
      break;
  }

  return ans;
}

int main() {
  string s;
  cin >> s;

  cout << rearrange(s);

  return 0;
}
