#include<vector>
#include<map>
#include<algorithm>

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
