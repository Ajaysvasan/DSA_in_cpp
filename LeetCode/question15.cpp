#include<vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};