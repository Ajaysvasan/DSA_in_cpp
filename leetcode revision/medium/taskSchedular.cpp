#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> freq(26, 0);
    for (char c : tasks) {
      freq[c - 'A']++;
    }

    sort(freq.begin(), freq.end());

    int maxFreq = freq[25];
    int countMax = 0;

    for (int i = 25; i >= 0 && freq[i] == maxFreq; i--) {
      countMax++;
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + countMax;

    return max((int)tasks.size(), emptySlots);
  }
};
