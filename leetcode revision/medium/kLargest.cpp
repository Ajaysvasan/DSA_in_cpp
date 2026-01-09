#include <functional>
#include <iostream>
#include <queue>
#include <vector>
class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int num : nums) {
      min_heap.push(num);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
    return min_heap.top();
  }
};

int main() {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution s;
  std::cout << s.findKthLargest(nums, k);
  return 0;
}
