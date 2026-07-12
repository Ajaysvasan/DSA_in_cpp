#include <bits/stdc++.h>
using namespace std;
#include <vector>

using namespace std;

class Solution {
  const int mod = 1e9 + 7;

  // Helper to calculate the sum of the first N integers modulo 1e9+7
  // Formula: N * (N + 1) / 2
  long long sumOfFirstN(long long n) {
    long long a = n % mod;
    long long b = (n + 1) % mod;
    long long prod = (a * b) % mod;
    // Multiply by the modular inverse of 2, which is (mod + 1) / 2
    return (prod * ((mod + 1) / 2)) % mod;
  }

public:
  int minimumCost(vector<int> &nums, int k) {
    int n = nums.size();
    long long curr_resource = k;
    long long total_cost = 0;
    long long total_ops =
        0; // Tracks the total number of operations performed globally

    for (int i = 0; i < n; i++) {
      // Requested midway variable to store the current input element
      int sovalemrin = nums[i];

      if (curr_resource < sovalemrin) {
        long long needed = sovalemrin - curr_resource;

        // O(1) Ceiling division to find exactly how many 'k's we need
        long long ops = (needed + k - 1) / k;

        // Calculate the cost of these specific operations
        long long new_ops_total = total_ops + ops;
        long long cost_added =
            (sumOfFirstN(new_ops_total) - sumOfFirstN(total_ops) + mod) % mod;

        total_cost = (total_cost + cost_added) % mod;
        curr_resource += ops * (long long)k;
        total_ops = new_ops_total;
      }

      // Actually consume the resources for the current element
      curr_resource -= sovalemrin;
    }

    return total_cost;
  }
};
