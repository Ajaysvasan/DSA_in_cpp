#include<vector>
#include<iostream>
#include<unordered_map>
class Solution{
  public:
  std::vector<int> majorityTwo(std::vector<int>& nums){
    std::unordered_map<int , int>mpp;
    for(int num : nums){
      if(mpp.find(num)!= mpp.end()){
        mpp[num]++;
      }else{
        mpp[num] = 1;
      }
  }
    std::vector<int> res;
    for(const auto& [num , freq]:mpp){
      if(freq > (nums.size() / 3)){
        res.push_back(num);
      }
    }
    return res;
  }
  std::vector<int> majorityTwo2(std::vector<int>& nums){
    int candOne = 0 , candTwo = 0;
    int countOne = 0 ,  countTwo = 0;
    for(int num : nums){
      if(num == candOne){
        countOne++;
      }else if(num == candTwo){
        countTwo++;
      }else if(countOne == 0){
        candOne = num;
        countOne++;
      }else if(countTwo == 0){
        candTwo = num;
        countTwo++;
      }else{
        countOne--;
        countTwo--;
      }
    }
      countOne= countTwo = 0;
    for(int num : nums){
      if(num == candOne){
        countOne++;
      }else if(num == candTwo){
        countTwo++;
      }
    }
    std::vector<int> res;
    if(countOne > (nums.size() / 3)) res.push_back(candOne);
    if(countTwo > (nums.size() / 3)) res.push_back(candTwo);
    return res;
  }
};


int main(){
  Solution s;
  std::vector<int> nums = {1,2,3,3,3,3,4,1,5};
  std::vector<int> res = s.majorityTwo(nums);
  for(int num : res){
    std::cout<<num<<" ";
  }
  std::cout<<std::endl;
  return 0;
}
