#include<iostream>
#include<vector>
#include<queue>

struct Task{
    std::string task;
    int priority;
    bool operator<(const Task& other) const{
        return this->priority < other.priority;
    }
};

main(){
    // Acts as a max heap
    std::priority_queue<int> max_heap;
    std::vector<int> random = {40,21,34,78,11,30};
    for(int num:random){
        max_heap.push(num);
    }
    while(!max_heap.empty()){
        std::cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    std::cout<<std::endl;
    // Acts as min queue
    std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;
    for(int num:random){
        min_heap.push(num);
    }
    while(!min_heap.empty()){
        std::cout<<min_heap.top()<<" ";
        min_heap.pop();
    }

    std::priority_queue<Task> taskQueue;

    taskQueue.push({"Write code",2});
    taskQueue.push({"Debug",5});
    taskQueue.push({"Sleep",1});
    std::cout<<std::endl;
    while (!taskQueue.empty()) {
        std::cout << taskQueue.top().task << " with priority " << taskQueue.top().priority << "\n";
        taskQueue.pop();
    }

}