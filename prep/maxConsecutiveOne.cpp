#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxConsequtiveOnes(vector<int> &nums, int k) {
    int countZeros = 0;
    int ans = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        countZeros++;
      }
      while (countZeros > k) {
        if (nums[left] == 0)
          countZeros--;
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  cout << s.maxConsequtiveOnes(nums, k);
}
