#include <iostream>
#include<vector>

void operator<<(std::ostream& COUT, std::vector<std::vector<int>>&arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            COUT<<arr[i][j]<<" ";
        }
        }
        COUT<<std::endl;
    }


int main() {
    std::vector<std::vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    std::cout<<arr;
    return 0;
}