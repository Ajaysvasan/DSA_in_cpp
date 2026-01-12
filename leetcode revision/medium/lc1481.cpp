#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        min_heap;
    unordered_map<int, int> freq;
    for (int num : arr) {
      freq[num]++;
    }
    for (auto &f : freq) {
      min_heap.push({f.second, f.first});
    }

    while (k > 0) {
      auto curr = min_heap.top();
      min_heap.pop();
      curr.first--;
      if (curr.first > 0) {
        min_heap.push(curr);
      }
      k--;
    }
    return min_heap.size();
  }
};
int main() {
  vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
  int k = 3;
  Solution s;
  cout << s.findLeastNumOfUniqueInts(arr, k);
}
