#include <unordered_set>
#include <vector>
int longestConsecutive(std::vector<int> &nums) {
  int maxCount = 1;
  std::unordered_set<int> st;
  for (int it : nums) {
    st.insert(it);
  }
  for (int i = 0; i < nums.size() - 1; i++) {
    if (st.find(nums[i] - 1) == st.end()) {
      int curr_count = 1;
      int curr_value = nums[i];
      while (st.find(curr_value) != st.end()) {
        curr_count++;
        curr_value++;
      }
      maxCount = std::max(maxCount, curr_count);
    }
  }
  return maxCount;
}
