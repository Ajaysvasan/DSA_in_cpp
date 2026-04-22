#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minMaxDiff(vector<int> &values, int k) {
    sort(values.begin(), values.end());
    int minDiff = INT_MAX;
    int minValue = values[0];
    int maxValue = values[values.size() - 1];
    int minValueFreq = 0;
    int maxValueFreq = 0;
    // finding the freq
    for (int i = 0; i < values.size(); i++) {
      if (values[i] == minValue)
        minValueFreq++;
      else
        maxValueFreq++;
    }
    return minDiff;
  }
};

int main() {
  Solution s;
  vector<int> values = {1, 1, 1, 10};
  int k = 3;
  cout << s.minMaxDiff(values, k);
}
