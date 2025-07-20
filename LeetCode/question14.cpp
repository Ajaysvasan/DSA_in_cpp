#include<vector>
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int expectedTotal = n * (n+1) /2;
        int actualTotal= 0;
        for(int num:nums){
            actualTotal += num;
        }
        return expectedTotal - actualTotal;
    }
};