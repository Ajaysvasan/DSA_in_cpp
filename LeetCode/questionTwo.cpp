#include<vector>
#include<iostream>
class Solution {
private:
std::vector<int> merge(std::vector<int>&nums1, std::vector<int>&nums2){
    std::vector<int> res(nums1.size() + nums2.size() , 0);
    int i = 0 , j = 0 , k = 0;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i] <= nums2[j]){
            res[k] = nums1[i];
            ++i;
        }else{
            res[k] = nums2[j];
            ++j;
        }
        ++k;
    }
    while(i<nums1.size()){
        res[k] = nums1[i];
        ++i;
        ++k;
    }
    while(j<nums2.size()){
        res[k] = nums2[j];
        ++j;
        ++k;
    }
    return res;
}
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> mergedArray = merge(nums1 , nums2);
        for(int value:mergedArray){
            std::cout<<value<<" ";
        }
        if(mergedArray.size() % 2 !=0){
            return mergedArray[mergedArray.size() / 2];
        }
        return ((double)mergedArray[mergedArray.size() / 2] + (double)mergedArray[(mergedArray.size()/2)-1]) / 2;
    }
};