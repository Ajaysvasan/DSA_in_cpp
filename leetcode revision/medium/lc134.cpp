#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total_gas = 0, total_cost = 0;
    int tank = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
      total_cost += cost[i];
      total_gas += gas[i];
      tank += gas[i] - cost[i];
      if (tank < 0) {
        start = i + 1;
        tank = 0;
      }
    }
    return (total_gas >= total_cost) ? start : -1;
  }
};

int main() {
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  Solution s;
  cout << s.canCompleteCircuit(gas, cost);
  return 0;
}
