#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        sort(nums.begin() , nums.end());
        for(int i = 0;i<nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1;j<nums.size()-2;j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int left = j + 1 , right = nums.size()-1;
                while(left < right){
                    int total = nums[i] + nums[j] + nums[left] + nums[right];
                    if(total < target){
                        left++;
                    }else if(total > target){
                        right--;
                    }else{
                        result.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                    }
                }
            }
        }
        return result;
    }
};