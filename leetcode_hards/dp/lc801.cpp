#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
  int minSwap(std::vector<int> &nums1, std::vector<int> &nums2) {
    int keep = 0, swap = 1;
    for (int i = 1; i < nums1.size(); i++) {
      int next_keep = INT_MAX;
      int next_swap = INT_MAX;
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        next_keep = std::min(next_keep, keep);
        next_swap = std::min(next_swap, swap + 1);
      }
      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        next_keep = std::min(next_keep, swap);
        next_swap = std::min(next_swap, keep + 1);
      }
      keep = next_keep;
      swap = next_swap;
    }
    return std::min(keep, swap);
  }
};
