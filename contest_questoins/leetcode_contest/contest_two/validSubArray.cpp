#include <vector>
class Solution {
  int getFirstNumber(int num) {
    while (num >= 10) {
      num /= 10;
    }
    return num;
  }

public:
  int countValidSubarrays(std::vector<int> &nums, int x) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for (int j = i; j < nums.size(); j++) {
        sum += nums[j];
        if (sum % 10 != x || getFirstNumber(sum) != x) {
          continue;
        }
        count++;
      }
    }
    return count;
  }
};
