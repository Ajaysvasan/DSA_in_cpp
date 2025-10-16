/*
 * Given a sorted array of nums and an integer x, write a program to find the lower bound of x.



The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.



If no such index is found, return the size of the array.


Examples:
Input : nums= [1,2,2,3], x = 2

Output:1

Explanation:

Index 1 is the smallest index such that arr[1] >= x.

Input : nums= [3,5,8,15,19], x = 9

Output: 3

Explanation:

Index 3 is the smallest index such that arr[3] >= x.
*/
#include<iostream>
#include<vector>
int lowerBound(std::vector<int>&nums, int x){
  int low =0 , high = nums.size() - 1;
  int ans = -1;
  while(low <= high){
    int mid = (low + high)/2;
    if(nums[mid]>=x){
      ans = mid;
      high = mid -1;
    }else{
      low = mid + 1;
    }
  }
  return ans;
}

int main(){
  std::vector<int>nums = {3,5,8,15,19};
  std::cout<<lowerBound(nums , 9);
  return 0;
}
