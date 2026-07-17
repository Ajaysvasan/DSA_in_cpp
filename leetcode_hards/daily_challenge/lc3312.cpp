#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  // O(n^2)
  vector<int> gcdValuesBruteForce(vector<int> &nums,
                                  vector<long long> &queries) {
    vector<int> gcdPairs;
    int n = nums.size();

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        gcdPairs.push_back(gcd(nums[i], nums[j]));
      }
    }
    sort(gcdPairs.begin(), gcdPairs.end());
    for (long long i = 0; i < queries.size(); i++) {
      if (queries[i] >= gcdPairs.size()) {
        ans.push_back(-1);
        continue;
      }
      ans.push_back(gcdPairs[queries[i]]);
    }
    return ans;
  }

public:
  vector<int> gcdValues(vector<int> &nums, vector<long long> &queries) {
    int n = *max_element(nums.begin(), nums.end());
    vector<int> freq(n + 1);
    for (int num : nums) {
      freq[num]++;
    }
    vector<int> multiplesCount(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        multiplesCount[i] += freq[j];
      }
    }
    vector<long long> exactGcd(n + 1);
    for (int i = n; i >= 1; i--) {
      long long c = multiplesCount[i];
      exactGcd[i] = c * (c - 1) / 2LL;
      for (int j = i * 2; j <= n; j += i) {
        exactGcd[i] -= exactGcd[j];
      }
    }
    vector<long long> prefix(n + 1, 0);
    prefix[0] = exactGcd[0];       // (Which is 0, since GCDs start at 1)
    for (int i = 1; i <= n; i++) { // Start at 1
      prefix[i] = prefix[i - 1] + exactGcd[i];
    }

    vector<int> res;
    for (long long q : queries) {
      // Use upper_bound to find the first prefix sum strictly greater than the
      // query index
      int gcd_val =
          upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
      res.push_back(gcd_val);
    }
    return res;
  }
};
