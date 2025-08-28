#include<vector>
#include<set>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> st;
        for(int num:nums) st.insert(num);
        int i = 0;
        for(int num:st) nums[i++] = num;
        return i;
    }
};