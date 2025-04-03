#include<iostream>
#include<vector>
main(){
    int var_one = 10;   
    int *ptr1 = &var_one;
    std::cout<<(int *)ptr1;
}