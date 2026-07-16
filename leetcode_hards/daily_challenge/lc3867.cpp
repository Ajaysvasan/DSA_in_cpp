#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
  long long gcdSum(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int global_max = *max_element(nums.begin(), nums.end());
    if (global_max == 1) {
      return nums.size() / 2;
    }
    vector<long long> prefixGrid(nums.size());
    prefixGrid[0] = nums[0];
    int currMaxElement = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      currMaxElement = max(currMaxElement, nums[i]);
      prefixGrid[i] = gcd(nums[i], currMaxElement);
    }
    long long sum = 0;
    int left = 0, right = prefixGrid.size() - 1;
    sort(prefixGrid.begin(), prefixGrid.end());
    while (left < right) {
      long long curr_gcd = gcd(prefixGrid[left], prefixGrid[right]);
      sum += curr_gcd;
      left++;
      right--;
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> nums = {3, 6, 2, 8};
  cout << sol.gcdSum(nums);
  return 0;
}
