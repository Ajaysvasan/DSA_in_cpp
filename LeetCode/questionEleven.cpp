#include<vector>
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int>res = {-1,-1};
        int left = binarySearch(nums,target,true);
        int right = binarySearch(nums,target,false);
        res[0] = left;
        res[1] = right;
        return res;
    }
    int binarySearch(std::vector<int>& nums , int target , bool isSearchngLeft){
        int left = 0, right = nums.size() - 1, idx = -1;
        while(left <=right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid -1;
            }else if(nums[mid] < target){
                left = left + 1;
            }else{
                idx = mid;
                if(isSearchngLeft){
                    right = mid -1;
                }else{
                    left = left +1;
                }
            }
        }
        return idx;
    }
};