#include<vector>
#include<iostream>
class Solution {
  // dict = {}
  // for num in nums:
  // if num in dict:
  // dict[num] += 1
  // else 
  // dict[num] = 1
  // for key , value in dict.items():
  // if (value == 1):
  // return key:wa
  //
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main(){
  Solution s;
  std::vector<int>nums = {1,1,3,3,5,5,4};
  std::cout<<s.singleNumber(nums);
  return 0;
}
