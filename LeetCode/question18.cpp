#include<vector>
#include<unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int,int> hash;
        for(int num:nums){
            if(hash.find(num) == hash.end()){
                hash[num] = 1;
            }else{
                hash[num]++;
            }
        }
        for(const auto pair:hash){
            if(pair.second > nums.size() / 2){
                return pair.first;
            }
        }
        return -1;
    }
};