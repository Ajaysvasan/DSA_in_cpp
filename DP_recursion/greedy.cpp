
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  vector<vector<int>> festivals;
  for (int i = 0; i < n; i++) {
    vector<int> festival;
    int data;
    int j = 0;
    while (j < 2) {
      cin >> data;
      festival.push_back(data);
      j++;
    }
    festivals.push_back(festival);
  }
  std::sort(festivals.begin(), festivals.end(),
            [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int count = 1;
  int end = festivals[0][1];
  for (int i = 1; i < festivals.size(); i++) {
    if (festivals[i][0] >= end) {
      count++;
      end = festivals[i][1];
    }
  }
  cout << count << endl;
  return 0;
}
