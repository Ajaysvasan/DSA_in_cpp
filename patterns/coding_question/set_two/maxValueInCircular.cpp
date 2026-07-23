#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {

    int totalSum = 0;

    // Normal Kadane (Maximum Subarray)
    int currMax = 0;
    int maxSum = nums[0];

    // Inverted Kadane (Minimum Subarray)
    int currMin = 0;
    int minSum = nums[0];

    for (int num : nums) {
      totalSum += num;

      // Maximum Subarray
      currMax = max(num, currMax + num);
      maxSum = max(maxSum, currMax);

      // Minimum Subarray
      currMin = min(num, currMin + num);
      minSum = min(minSum, currMin);
    }

    // Corner case:
    // If every element is negative, minSum == totalSum.
    // totalSum - minSum would become 0 (invalid because we'd exclude the whole
    // array).
    if (maxSum < 0)
      return maxSum;

    return max(maxSum, totalSum - minSum);
  }
};

int main() {
  vector<int> nums = {8, -1, 3, 4};

  Solution obj;
  cout << obj.maxSubarraySumCircular(nums) << endl;

  return 0;
}
