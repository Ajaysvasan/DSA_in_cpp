#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
  string str;
  if (!(cin >> str))
    return 0;

  unordered_map<char, int> mpp;
  int left = 0;
  int max_len = 0;

  for (int right = 0; right < str.size(); right++) {
    // 1. Add the new character to our window map
    mpp[str[right]]++;

    // 2. If adding this character created a duplicate, shrink the
    // window from the left until the duplicate is gone.
    while (mpp[str[right]] > 1) {
      mpp[str[left]]--;
      left++;
    }

    // 3. Now the window is valid (no duplicates). Update the max length.
    max_len = max(max_len, right - left + 1);
  }

  cout << max_len << "\n";
  return 0;
}
