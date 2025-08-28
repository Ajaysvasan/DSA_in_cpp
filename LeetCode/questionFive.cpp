#include<vector>
#include<algorithm>
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin() , nums.end());
        for(int i = 0;i<nums.size() - 2;i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < abs(target - res)){
                    res = sum;
                }
                if(sum == target) return target;
                else if(sum < target) left++;
                else right--;
            }
        }
        return res;
    }
};