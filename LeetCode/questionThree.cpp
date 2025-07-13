#include<string>
#include<vector>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.empty()) 
            return "";
        std::string pref = strs[0];
        int prefLen = pref.length();
        for(int  i = 0;i<strs.size();i++){
            std::   string s = strs[i];
            while(prefLen > s.length() || pref != s.substr(0 , prefLen)){
                prefLen--;
                if(prefLen == 0){
                    return "";
                }
                pref = pref.substr(0 , prefLen);
            }
        }
        return pref;
    }
};