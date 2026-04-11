#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
  // {idx , currentSum }, count;
  map<pair<int, int>, int> memo;

public:
  int findCombinations(vector<int> &nums, int target, int idx,
                       int current_sum) {
    if (idx == nums.size()) {
      return current_sum == target ? 1 : 0;
    }

    if (memo.count({idx, current_sum})) {
      return memo[{idx, current_sum}];
    }

    int add = findCombinations(nums, target, idx + 1, current_sum + nums[idx]);

    int subtract =
        findCombinations(nums, target, idx + 1, current_sum - nums[idx]);

    return memo[{idx, current_sum}] = add + subtract;
  }

  int findTargetSumWays(vector<int> &nums, int target) {
    memo.clear();
    return findCombinations(nums, target, 0, 0);
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  int count = s.findTargetSumWays(nums, target);
  cout << count << endl;
  return 0;
}
