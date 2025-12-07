#include <map>
#include <string>
#include <utility>

using namespace std;
int countSubstrings(string s) {
  int c0 = 0, c1 = 0, c2 = 0;
  long long ans = 0;

  map<pair<int, int>, int> freq;
  freq[{0, 0}] = 1;

  for (char ch : s) {
    if (ch == '0')
      c0++;
    else if (ch == '1')
      c1++;
    else
      c2++;

    int dx = c1 - c0;
    int dy = c2 - c0;

    ans += freq[{dx, dy}];
    freq[{dx, dy}]++;
  }
  return ans;
}
