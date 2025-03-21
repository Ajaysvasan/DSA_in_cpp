#include<stack>
#include<iostream>

using namespace std;

void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

main(){
    stack<int> st;
    for(int i = 0;i<11;++i){
        int temp = 2*i + 1;
        st.push(temp);
    }

    int temp = st.top();
    cout<<temp<<endl;
    print(st);
}