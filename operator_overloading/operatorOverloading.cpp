#include <iostream>
#include<vector>
#include<list>

struct Details{
    std::string name;
    int age;

    Details(std::string name,int age){
        this->name = name;
        this->age = age;
    }

    bool operator==(const Details& details){
        return this->name == details.name;
    }
};

struct Collect{
    std::list<Details> get_details;
    void operator+=(const Details& details){
        this->get_details.push_back(details);
    }
    void operator-=(const Details& details){
        this->get_details.remove(details);
    }
};

std::ostream& operator<<(std::ostream& COUT, const std::vector<std::vector<int>>&arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            COUT<<arr[i][j]<<" ";
        }
        COUT<<std::endl;
        }
        COUT<<std::endl;
        return COUT;
    }

    std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>>&arr1,const std::vector<std::vector<int>>&arr2){
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

void operator~(std::vector<std::vector<int>>&matrix){
    for(int i = 0;i<matrix.size();i++){
        for(int j = i+1;j<matrix[0].size();j++){
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

void transpose(std::vector<std::vector<int>>&matrix){
    for(int i = 0;i<matrix.size();i++){
        for(int j = i+1;j<matrix[0].size();j++){
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

std::ostream& operator<<(std::ostream& COUT,const Details& detail){
    COUT<<detail.name<<std::endl;
    COUT<<detail.age<<std::endl;
    return COUT;
}

std::ostream& operator<<(std::ostream& COUT,const Collect& collect){
    for(Details data: collect.get_details){
        COUT<<data<<std::endl;
    }
    return COUT;
}

main() {
    std::vector<std::vector<int>> matrix_one = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> matrix_two = {{10,11,12},{13,14,15},{16,17,18}};
    std::vector<std::vector<int>> matrix_three = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> result = matrix_one*matrix_two;
    std::cout<<"result Matrix\n"<<result<<"matrix One\n"<<matrix_one<<"matrix Two\n"<<matrix_two;

    Details d1 = Details("Ajay",19);
    Details d2 = Details("Anish",19);

    Collect collect;
    collect+=d1;
    collect+=d2;
    collect-=d2;

    std::cout<<collect;


    std::cout<<"Before Transpsosing\n"<<matrix_three;
    ~matrix_three;
    std::cout<<"After Transposing\n"<<matrix_three;

}