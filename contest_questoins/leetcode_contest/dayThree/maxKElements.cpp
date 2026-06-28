#include <functional>
#include <iostream>
#include <queue>
#include <vector>
class Solution {
public:
  long long maxSum(std::vector<int> &nums, int k, int mul) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (long long i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      while (pq.size() > k) {
        pq.pop();
      }
    }
    long long totalSum = 0;
    std::vector<long long> kValues;
    while (!pq.empty()) {
      kValues.push_back(pq.top());
      pq.pop();
    }
    for (long long i = kValues.size() - 1; i >= 0; i--) {
      if (mul != 0) {
        totalSum += (kValues[i] * mul);
        mul--;
      } else {
        totalSum += kValues[i];
      }
    }
    return totalSum;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  std::vector<int> nums = {6, 1, 2, 9};
  int k = 3;
  int mul = 2;
  std::cout << sol.maxSum(nums, k, mul);
  return 0;
}
