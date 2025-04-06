#include<iostream>

// Queue -> first in first out

// can be implemented in both arrays and List format

// List Implementation
class QueueList{
    private:
        int m_count =0;
        struct Node{
            int data;
            Node* next;
        } *head,*top,*last;
    public:
        QueueList(){
            head = top = last = nullptr;
        }
        void insert(int data){
            m_count++;
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = nullptr;
            if(!head){
                head = top = last = new_node;
                return;
            }
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_node;
            last = new_node;
        }

        void remove(){
            if(!head){
                std::cout<<"Queue underflow"<<std::endl;
                return;
            }
            if(top == last){
                head = top = last =  nullptr;
                m_count--;
                return;
            }
            Node* temp = top;
            head = top = temp->next;
            delete temp;
            m_count--;
        }

        void print(){
            Node* temp = head;
            while(temp){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }

        ~QueueList(){
            std::cout<<"Destructor invoked"<<std::endl;
            while(head){
                remove();
            }
        }
};

// Array implementation

#include <iostream>
using namespace std;

class QueueArray {
private:
    int* arr;
    int frontIdx;
    int rearIdx;
    int capacity;

public:
    QueueArray(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = -1;
    }

    ~QueueArray() {
        delete[] arr;
    }

    bool isEmpty() {
        return frontIdx > rearIdx;
    }

    bool isFull() {
        return rearIdx == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rearIdx] = value;
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[frontIdx++] << " dequeued\n";
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIdx];
    }

    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rearIdx];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = frontIdx; i <= rearIdx; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    QueueList queue_one;
    for(int i = 0;i<11;i++){
        queue_one.insert(i);
    }
    std::cout<<"Queue value"<<std::endl;
    queue_one.print();

    queue_one.remove();
    queue_one.print();

        QueueArray q(5);
    
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
    
        q.display();
    
        q.dequeue();
        q.display();
    
        cout << "Front: " << q.front() << endl;
        cout << "Rear: " << q.rear() << endl;
    
    return 0;
}