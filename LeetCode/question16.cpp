#include<vector>
#include<map>
#include<algorithm>
#include<iostream>

class Solution{
public:
    int longestSubarray(std::vector<int> &nums, int k){
        std::map<int , int> mpp;
        int sum = 0;
        int maxLength = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sum==k){
                maxLength = std::max(maxLength , i+1);
            }
            int rem = sum - k;
            if(mpp.find(rem)!=mpp.end()){
                int len = i - mpp[rem];
                maxLength = std::max(maxLength , len);
            }
            mpp[sum] = i;
        }
        return maxLength;
    }
};

int main(){
  std::vector<int>nums  ={2,3,1,1,1};
  Solution s;
  std::cout<<s.longestSubarray(nums,3); 
}
