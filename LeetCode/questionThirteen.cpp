#include<vector>
#include<algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            if(nums[right]!=0){
                std::swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};