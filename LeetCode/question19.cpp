#include<vector>
#include<iostream>

int main(){
    std::vector<int>nums = {-2,1,-3,4,-1,2,-5,4};
    int maxSum = 0;
    for(int num:nums){
        maxSum += num;
    }
    std::cout<<"\n"<<maxSum;
    return 0;
}