#include <bits/stdc++.h>
using namespace std;

// Brute force
// class Solution {
//   // value of k should be u < k <= v
//   bool pathInInterMedemiateQueries(int u, int k, vector<int> &nums,
//                                    int maxDiff) {
//     int prev_value = u;
//     for (int i = u + 1; i < k; i++) {
//       if (abs(nums[prev_value] - nums[i]) > maxDiff) {
//         return false;
//       }
//       prev_value = i;
//     }
//     return true;
//   }

// public:
//   vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
//                                     vector<vector<int>> &queries) {
//     vector<bool> ans;
//     for (vector<int> &query : queries) {
//       int u = query[0];
//       int v = query[1];
//       if (v >= n) {
//         ans.push_back(false);
//         continue;
//       }
//       if (abs(v - u) > 1) {
//         ans.push_back(pathInInterMedemiateQueries(u, v, nums, maxDiff));
//         continue;
//       }
//       if (abs(nums[u] - nums[v]) <= maxDiff) {
//         ans.push_back(true);
//       } else {
//         ans.push_back(false);
//       }
//     }
//     return ans;
//   }
// };
//
class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<int> prefix(n, 0);
    for (int i = 0; i < n - 1; i++) {
      int is_valid = (abs(nums[i] - nums[i + 1]) <= maxDiff) ? 1 : 0;
      prefix[i + 1] = prefix[i] + is_valid;
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto &query : queries) {
      int u = query[0];
      int v = query[1];
      if (u >= n || v >= n) {
        ans.push_back(false);
        continue;
      }
      int left = min(u, v);
      int right = max(u, v);
      int required_jumps = right - left;
      int actual_valid_jumps = prefix[right] - prefix[left];
      ans.push_back(actual_valid_jumps == required_jumps);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  int n = 4;
  vector<int> nums = {2, 5, 6, 8};
  int maxDiff = 2;
  vector<vector<int>> queries = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  Solution sol;
  vector<bool> ans = sol.pathExistenceQueries(n, nums, maxDiff, queries);
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i]) {
      cout << 1 << " ";
    } else {
      cout << 0 << " ";
    }
  }
  return 0;
}
