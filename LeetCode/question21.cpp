//Given an array of size n and an integer k return the total number of subarrays whoes sum = k

#include<iostream>
#include<vector>
#include<map>
class Solution{
	public:
	int subarray(std::vector<int>&nums,int k){
		std::map<int , int>hash;
		hash[0] = 1;
		int prefSum = 0 , count = 0;
		for(int i = 0;i<nums.size();i++){
			prefSum += nums[i];
			int remove = prefSum - k;
			count += hash[remove];
			hash[prefSum] += 1;
		}
		return count;
	
	}
		
};

int main(){
	std::vector<int> nums = {1,2,3,-3,1,1,1,4,2,-3};
	Solution s;
	if(s.subarray(nums , 3) == 8){
		std::cout<<"Test case passed\n";
		return EXIT_SUCCESS;
	}
		
	std::cerr<<"Test case failed\n";
	return EXIT_FAILURE;
}
