#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0,mid = 0 , high = nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                std::swap(nums[mid++], nums[low++]);
            }else if(nums[mid] == 1){
                mid++;
            }else{
                std::swap(nums[mid] , nums[high--]);
            }
        }
    }
};

int main(){
    std::vector<int>colors = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(colors);
    for(int color:colors){
        std::cout<<color<<" ";
    }
    return 0;
}