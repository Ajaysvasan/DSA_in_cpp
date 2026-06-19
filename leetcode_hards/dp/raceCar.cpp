#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
  int racecar(int target) {
    queue<vector<int>> q;
    q.push({0, 0, 1});

    unordered_set<string> visited;
    visited.insert("0,1");

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      int moves = curr[0];
      int pos = curr[1];
      int speed = curr[2];

      if (pos == target)
        return moves;

      int new_pos = pos + speed;
      int new_speed = speed * 2;

      string stateA = to_string(new_pos) + "," + to_string(new_speed);

      if (visited.find(stateA) == visited.end() && new_pos > 0 &&
          new_pos < (target * 2)) {
        visited.insert(stateA);
        q.push({moves + 1, new_pos, new_speed});
      }

      int rev_speed = (speed > 0) ? -1 : 1;
      string stateR = to_string(pos) + "," + to_string(rev_speed);

      if (visited.find(stateR) == visited.end()) {
        visited.insert(stateR);
        q.push({moves + 1, pos, rev_speed});
      }
    }

    return 0;
  }
};
