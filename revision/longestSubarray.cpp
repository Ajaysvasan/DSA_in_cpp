#include <iostream>
#include <unordered_map>
#include <vector>

int longestSubArray(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> mpp;
  int maxLen = 0;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum+= nums[i];
    if(sum == k){
      maxLen = std::max(maxLen , i+1);
    }
    int rem =sum - k; 
    if(mpp.find(rem) != mpp.end()){
      int len = i - mpp[rem];
      maxLen = std::max(maxLen ,len);
    }
      mpp[sum] = i;
  }
  return maxLen;
}

int main(){
  std::vector<int>nums = {2 , 3 , 1,1,1};
  std::cout<<longestSubArray(nums,3);
  return 0;
}
