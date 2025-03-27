#include<iostream>
#include<stack>


class SortStack{
    private:
        void sortedStack(std::stack<int>&s , int element){
            if(s.empty() || s.top() > element){
                s.push(element);
                return;
            }
            int top = s.top();
            s.pop();
            sortedStack(s,element);
            s.push(top);
        }
    public:
        void sortStack(std::stack<int>&s){
            if(s.empty()) return;
            int top = s.top();
            s.pop();
            sortStack(s);
            sortedStack(s,top);
        }

        void print(std::stack<int>&s){
            while(!s.empty()){
                std::cout<<s.top()<<" ";
                s.pop();
            }
        }
};

main(){
    SortStack s;
    std::stack<int> arr;
    arr.push(32);
    arr.push(0);
    arr.push(12);
    arr.push(1);
    arr.push(41);
    s.sortStack(arr);
    s.print(arr);
}