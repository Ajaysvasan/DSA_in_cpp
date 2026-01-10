#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> heap;
    for (int stone : stones)
      heap.push(stone);
    while (heap.size() > 1) {
      int stone_one = heap.top();
      heap.pop();
      int stone_two = heap.top();
      heap.pop();
      heap.push(stone_one - stone_two);
    }
    return heap.size() > 0 ? heap.top() : 0;
  };
};

int main() {
  Solution s;
  vector<int> stones = {1};
  cout << "the answer is :" << s.lastStoneWeight(stones);
  return 0;
}
