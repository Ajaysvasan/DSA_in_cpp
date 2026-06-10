#include <queue>
#include <vector>

class Solution {
public:
  int minRefuelStops(int target, int startFuel,
                     std::vector<std::vector<int>> &stations) {
    int current_pos = 0;
    std::priority_queue<int> pq;
    int ans = 0;

    for (int i = 0; i < stations.size(); i++) {
      int distance = stations[i][0] - current_pos;
      startFuel -= distance;
      current_pos = stations[i][0]; // Update our position

      while (startFuel < 0 && !pq.empty()) {
        startFuel += pq.top(); // ADD the fuel, do not assign
        pq.pop();
        ans++;
      }

      if (startFuel < 0)
        return -1;

      pq.push(stations[i][1]);
    }

    int final_distance = target - current_pos;
    startFuel -= final_distance;

    while (startFuel < 0 && !pq.empty()) {
      startFuel += pq.top();
      pq.pop();
      ans++;
    }

    return startFuel < 0 ? -1 : ans;
  }
};
