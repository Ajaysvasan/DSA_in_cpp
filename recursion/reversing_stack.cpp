#include<iostream>
#include<stack>

class ReverseStack{
    public:
        void sortedStack(std::stack<int>&s ,int element){
            if(s.empty() || element > s.top()){
                s.push(element);
                return;
            }
            int top = s.top();
            s.pop();
            sortedStack(s,element);
            s.push(top);
        }

        void sortStack(std::stack<int>&s){
            if(s.empty()) return;
            int top = s.top();
            s.pop();
            sortStack(s);
            sortedStack(s,top);
        }
        void print(std::stack<int>&s){
            while(!s.empty()){
                std::cout<<s.top()<<std::endl;
                s.pop();
            }
        }
};

main(){
    ReverseStack rs;
    std::stack<int> s;
    s.push(22);
    s.push(0);
    s.push(7);
    s.push(3);
    rs.sortStack(s);
    rs.print(s);

}