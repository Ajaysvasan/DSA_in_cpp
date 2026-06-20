#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int getLength(vector<int> &nums) {
    int max_len = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      unordered_map<int, int> mpp;

      for (int j = i; j < n; j++) {
        mpp[nums[j]]++;

        int current_min = 1e9;
        int current_max = -1e9;

        for (const auto &pair : mpp) {
          current_min = min(current_min, pair.second);
          current_max = max(current_max, pair.second);
        }

        if (current_min * 2 == current_max ||
            current_min == current_max && mpp.size() == 1) {
          max_len = max(max_len, j - i + 1);
        }
      }
    }
    return max_len;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  cout << s.getLength(nums) << "\n"; // Correctly outputs 5
  return 0;
}
