// Given an array nums of size n and an integer k,
//     find the length of the longest sub - array that sums to k.If no such sub
//     -
//         array exists,
//     return 0.
//
//            Examples : Input
//     : nums = [ 10, 5, 2, 7, 1, 9 ],
//       k = 15
//
//           Output : 4
//
//           Explanation :
//
//     The longest sub -
//     array with a sum equal to 15 is[5, 2, 7, 1],
//       which has a length of 4. This sub - array starts at index 1 and
//           ends at index 4,
//       and the sum of its elements(5 + 2 + 7 + 1) equals 15. Therefore,
//       the length of this sub - array is 4.
//
//           Input : nums = [ -3, 2, 1 ],
//       k = 6
//
//           Output : 0
//
//           Explanation :
//
//     There is no sub
//     -
//     array in the array that sums to 6. Therefore,
//       the output is 0.

#include <iostream>
#include <unordered_map>
#include <vector>
int longestSubarray(std::vector<int> &nums, int k) {
  int maxSubArrayLength = 0;
  std::unordered_map<int, int> mpp;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum == k) {
      maxSubArrayLength = std::max(maxSubArrayLength, i + 1);
    }
    int rem = sum - k;
    if (mpp.find(rem) != mpp.end()) {
      int length = i - mpp[rem];
      maxSubArrayLength = std::max(maxSubArrayLength, length);
    } else {
      mpp[sum] = i;
    }
  }
  return maxSubArrayLength;
}

int main() {
  std::vector<int> nums = {10, 5, 2, 7, 1, 9};
  std::cout << longestSubarray(nums, 15);
  return 0;
}
