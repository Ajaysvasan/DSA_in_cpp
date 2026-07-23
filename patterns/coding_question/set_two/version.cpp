#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
  int i = 0, j = 0;
  int n = version1.size();
  int m = version2.size();

  while (i < n || j < m) {

    int num1 = 0;
    while (i < n && version1[i] != '.') {
      num1 = num1 * 10 + (version1[i] - '0');
      i++;
    }

    int num2 = 0;
    while (j < m && version2[j] != '.') {
      num2 = num2 * 10 + (version2[j] - '0');
      j++;
    }

    if (num1 > num2)
      return 1;
    if (num1 < num2)
      return -1;

    // Skip the dots
    if (i < n && version1[i] == '.')
      i++;
    if (j < m && version2[j] == '.')
      j++;
  }

  return 0;
}

int main() {
  string version1, version2;

  cin >> version1 >> version2;

  cout << compareVersion(version1, version2) << endl;

  return 0;
}
