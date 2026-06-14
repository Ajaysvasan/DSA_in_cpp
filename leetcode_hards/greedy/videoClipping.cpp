#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int time) {

    sort(clips.begin(), clips.end());

    int clipsUsed = 0;
    int currentEnd = 0;
    int farthest = 0;
    int i = 0;
    int n = clips.size();

    while (currentEnd < time) {

      while (i < n && clips[i][0] <= currentEnd) {
        farthest = max(farthest, clips[i][1]);
        i++;
      }

      if (farthest == currentEnd) {
        return -1;
      }

      clipsUsed++;
      currentEnd = farthest;
    }

    return clipsUsed;
  }
};
