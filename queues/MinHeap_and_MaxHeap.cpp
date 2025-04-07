#include<iostream>
#include<vector>
#include<queue>

class MaxHeap{
    private:
        std::vector<int> heap;
        void heapify_up(int i){
            while(i>0 && heap[i]>heap[(i-1)/2]){
                std::swap(heap[i],heap[(i-1)/2]);
                i = (i-1)/2;
            }
        }

        void heapifydown(int i){
            int n = heap.size();
            while(2 * i + 1 < n){
                int largest = i;
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if(left < n && heap[left]>heap[largest]) largest = left;
                if(right < n && heap[right] > heap[largest]) largest = right;
                if(largest == i) break;
                std::swap(heap[largest],heap[i]);
                i = largest;
            }
        }
        bool searchMax(int target, int curr_index){
            if(heap.empty() || curr_index >= heap.size()) return false;
        
            if(heap[curr_index] == target) return true;
            return searchMax(target, 2 * curr_index + 1) || searchMax(target, 2 * curr_index + 2);
        }
        

    public:
        void insert(int data){
            heap.push_back(data);
            heapify_up(heap.size()-1);
        }

        void removeAt(int node_index){
            int n = heap.size();
            if(node_index >= n){
                std::cout<<"Invalid Node index"<<std::endl;
                return;
            }
            std::swap(heap[node_index],heap[n-1]);
            heap.pop_back();
            if(node_index < n){
                if(node_index > 0 && heap[node_index] > heap[(node_index-1)/2])
                    heapify_up(node_index);
                else
                    heapifydown(node_index);
            }
        }

        void removeMax(){
            if(heap.empty()){
                std::cout<<"The heap is empty"<<std::endl;
                return;
            }
            heap[0] = heap.back();
            heap.pop_back();
            heapifydown(0);
        }

        int getMax(){
            return heap.empty() ? -1 : heap[0];
        }

        bool search(int target){
            return searchMax(target,0);
        }

        void display(){
            for(int val:heap){
                std::cout<<val<<" ";
            }
            std::cout<<std::endl;
        }
    
};

class MinHeap{
    private:
        std::vector<int> heap;
        void heapify_up(int i) {
            while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
                std::swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

        void heapifydown(int i){
            int n = heap.size();
            while(2 * i + 1 < n){
                int min_index = i;
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if(left < n && heap[left]<heap[min_index]) min_index = left;
                if(right < n && heap[right] < heap[min_index]) min_index = right;
                if(min_index == i) break;
                std::swap(heap[min_index],heap[i]);
                i = min_index;
            }
        }

        bool searchMin(int target,int curr_index){
            if(heap.empty()||heap.size() <= curr_index) return false;
            if(heap[curr_index] > target){
                return false;
            }
            if(heap[curr_index] == target) return true;
            return searchMin(target,2 * curr_index + 1) || searchMin(target,2 * curr_index + 2);
        }   

    public:
        void insert(int data){
            heap.push_back(data);
            heapify_up(heap.size()-1);
        }

        void removeAt(int node_index){
            int n = heap.size();
            if(node_index >= n){
                std::cout<<"Invalid Node index"<<std::endl;
                return;
            }
            std::swap(heap[node_index],heap[n-1]);
            heap.pop_back();
            if(node_index < n){
                if(node_index > 0 && heap[node_index] < heap[(node_index-1)/2]){
                    heapify_up(node_index);
                }else{
                    heapifydown(node_index);
                }
            }
        }

        void removeMin(){
            if(heap.empty()){
                std::cout<<"The heap is empty"<<std::endl;
                return;
            }
            heap[0] = heap.back();
            heap.pop_back();
            heapifydown(0);
        }

        int getMin(){
            return heap.empty() ? -1 : heap[0];
        }

        bool search(int target){
            return searchMin(target,0);
        }   

        void display(){
            for(int val:heap){
                std::cout<<val<<" ";
            }
            std::cout<<std::endl;
        }

};

main(){
    MaxHeap max_heap;
    std::vector<int> keys = {7,10,1,23,5,15,17,9,11,39,35,8,40,25};
    for(int key:keys){
        max_heap.insert(key);
    }
    max_heap.display();
    max_heap.removeAt(2);
    max_heap.display();
    std::cout<<max_heap.getMax()<<std::endl;
    std::cout<<max_heap.search(7)<<std::endl;

    MinHeap min_heap;
    for(int key:keys){
        min_heap.insert(key);
    }
    min_heap.display();
    min_heap.removeAt(4);
    min_heap.display();
    std::cout<<min_heap.search(23)<<std::endl;
}