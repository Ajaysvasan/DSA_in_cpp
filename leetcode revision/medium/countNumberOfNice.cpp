#include <vector>
class Solution {
public:
  int atMost(std::vector<int> &nums, int k) {
    int left = 0, odd = 0, count = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] % 2 == 1)
        odd++;

      while (odd > k) {
        if (nums[left] % 2 == 1)
          odd--;
        left++;
      }

      count += (right - left + 1);
    }
    return count;
  }

  int numberOfSubarrays(std::vector<int> &nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
  }
};
