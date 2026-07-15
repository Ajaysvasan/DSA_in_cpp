#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  string str = "ZOHOCORPORATION";
  string str2 = "PORT";
  vector<int> firstOccurances;
  for (char ch : str2) {
    size_t pos = str.find(ch);

    // string::npos means "not found". We only push if the character actually
    // exists.
    if (pos != string::npos) {
      firstOccurances.push_back(pos);
    }
  }
  int min_value = *min_element(firstOccurances.begin(), firstOccurances.end());
  int max_value = *max_element(firstOccurances.begin(), firstOccurances.end());
  for (int i = min_value; i <= max_value; i++) {
    cout << str[i];
  }
  return 0;
}
