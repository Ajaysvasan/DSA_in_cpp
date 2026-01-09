#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s)
      freq[c]++;

    priority_queue<pair<int, char>> pq;
    for (auto &p : freq) {
      pq.push({p.second, p.first});
    }

    string result = "";
    pair<int, char> prev = {0, '#'}; // previous used char

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      result.push_back(curr.second);
      curr.first--;

      if (prev.first > 0) {
        pq.push(prev);
      }

      prev = curr;
    }

    return result.size() == s.size() ? result : "";
  }
};

int main() {
  Solution s;
  string s1 = "aab";
  string s2 = "aaab";
  cout << "Output for the first string: " << s.reorganizeString(s1) << endl
       << "Output for the second string: " << s.reorganizeString(s2);
  return 0;
}
