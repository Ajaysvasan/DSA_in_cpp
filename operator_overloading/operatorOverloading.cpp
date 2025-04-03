#include <iostream>
#include<vector>

void  operator<<(std::ostream& COUT, std::vector<std::vector<int>>&arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            COUT<<arr[i][j]<<" ";
        }
        COUT<<std::endl;
        }
    }

    std::vector<std::vector<int>> operator*(std::vector<std::vector<int>>&arr1,std::vector<std::vector<int>>&arr2){
        if(arr1[0].size() != arr2.size()) return {{}};
        std::vector<std::vector<int>> result(arr1[0].size(), std::vector<int>(arr2.size(), 0));
        for(int i = 0;i<arr1.size();++i){
            for(int j = 0;j<arr2[0].size();++j){
                for(int k = 0;k<arr1[0].size();++k){
                    result[i][j] += (arr1[i][k]*arr2[k][j]);
                }
            }
        }
        return result;

}

int main() {
    std::vector<std::vector<int>> matrix_one = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> matrix_two = {{10,11,12},{13,14,15},{16,17,18}};
    std::vector<std::vector<int>> result = matrix_one*matrix_two;
    std::cout<<result;
    return 0;
}