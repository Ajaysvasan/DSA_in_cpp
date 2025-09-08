#include<iostream>
#include <pthread.h>
#include<vector>
#include<unordered_map>
int repeatingNum(std::vector<int>&nums){
        int element= 0 , count = 0;
        for(int num:nums){
            if(num == element){
                count++;
            }else if(count == 0){
                element = num;
                count++;
            }else{
                count--;
            }
        }
        count = 0;
        for(int num:nums){
            if(num == element){
                count++;
            }
        }
        return (count == 2)?element:0;
    }

int missingNumber(std::vector<int>&nums){
  std::unordered_map<int , int>mpp;
  for(int num:nums){
    if(mpp.find(num) == mpp.end()){
      mpp[num] = 1;
    }
  }
  for(int i = 1;i<mpp.size();i++){
    if(mpp.find(i) == mpp.end()){
      return i;
    }
  }
 return 0;
}

int main(){
  std::vector<int>nums = {1, 2, 3, 6, 7, 5, 7};
  std::cout<<repeatingNum(nums)<<std::endl;
  std::cout<<missingNumber(nums);
}
