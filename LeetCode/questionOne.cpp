#include<vector>
#include<unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int , int> complementTable;
        for(int i = 0;i<nums.size();++i){
            int complement = target - nums[i];
            if(complementTable.find(complement)!=complementTable.end()){
                return {i , complementTable[complement]};
            }
            complementTable[nums[i]] = i;
        }
        return {};
    }
};