#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    unordered_map<int, int> rank;
    vector<int> nums = arr;
    int curr_rank = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
      if (rank.find(arr[i]) == rank.end()) {
        rank[arr[i]] = curr_rank;
        curr_rank++;
      }
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      res.push_back(rank[nums[i]]);
    }
    return res;
  }
};
