#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }

        return count;
    }
};