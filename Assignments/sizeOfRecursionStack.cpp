#include<iostream>

void recursion(long long* count){
  count++;
  recursion(count);
}

int main(){
long long count = 0;
  try{
    recursion(&count);
  }catch(...){
    std::cout<<"The limit of the recursion stack is : "<<count;
  }
}
