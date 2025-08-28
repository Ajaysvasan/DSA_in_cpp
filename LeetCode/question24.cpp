#include <climits>
#include<iostream>
#include<vector>

class Solution{
public:
  int maxSubArray(std::vector<int>& nums){
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0;i<nums.size();i++){
      currentSum += nums[i];
      maxSum = std::max(currentSum , maxSum);
    }
    return maxSum;
  }
};

int main(){
  Solution s;
  std::vector<int>nums = {2 , 3, 5, -2, 7 , -4};
  std::cout<<s.maxSubArray(nums);
  return 0;
}
