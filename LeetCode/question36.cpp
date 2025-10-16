#include<vector>
class Solution {
public:
    int findKRotation(std::vector<int> &nums)  {
        int idx = -1;
        int minimum = 9999;
        int low = 0 , high = nums.size()-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high] ){
                if(nums[low ]< minimum){
                    minimum = nums[low];
                    idx = low;
                }
                break;
            }
            if(nums[low]<= nums[mid]){
                if(nums[low] < minimum){
                    idx = low;
                    minimum = nums[low];
                }
                low = mid + 1;
            }else{
                high = mid -1;
                if(nums[mid] < minimum){
                    minimum = nums[mid];
                    idx = mid;
                }
            }
        }
        return idx;
    }
};

