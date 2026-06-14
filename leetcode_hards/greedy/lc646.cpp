#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int count = 1;
    if (pairs.size() == 0)
      return 0;
    if (pairs.size() == 1)
      return count;
    sort(pairs.begin(), pairs.end(),
         [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    int curr_end = pairs[0][1];
    for (int i = 0; i < pairs.size(); i++) {
      if (curr_end < pairs[i][0]) {
        curr_end = pairs[i][1];
        count++;
      }
    }
    return count;
  }
};
