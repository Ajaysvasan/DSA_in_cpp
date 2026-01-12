#include <algorithm>
#include <cinttypes>
#include <functional>
#include <iostream>
#include <pthread.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    sort(
        trips.begin(), trips.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;

    int current_number_of_passengerns = 0;

    for (const auto &trip : trips) {
      int number_of_passengers = trip[0], start = trip[1], end = trip[2];
      current_number_of_passengerns += number_of_passengers;
      while (!heap.empty() && heap.top().first <= start) {
        int temp = heap.top().second;
        current_number_of_passengerns -= temp;
        heap.pop();
      }
      if (current_number_of_passengerns > capacity)
        return false;

      heap.push({end, number_of_passengers});
    }
    return true;
  }
};
int main() {
  vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
  Solution s;
  if (s.carPooling(trips, 4)) {
    cout << "true";
  } else {
    cout << "false";
  }
  return 0;
}
