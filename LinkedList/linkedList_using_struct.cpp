#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class SLinkedList{
    Node* head;
    int count = 0;
    public:
    SLinkedList(): head(NULL){}

    void insertAtBeginning(int data){
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        ++count;
    }

    void insertAtEnd(int data){
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        if(!head){
            head = new_node;
            ++count;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        ++count;
    }

    void insertAtPosition(int data, int pos){
        if(pos == 1){
            insertAtBeginning(data);
            return;
        }else if(pos == count){
            insertAtEnd(data);
            return;
        }else if(pos > count||pos < 1){
            cout<<"Invalid pos";
            return;
        }
        Node* new_node = new Node();
        new_node->data = data;
        Node* temp = head;
        for(int i = 1;i<pos - 1 && temp;i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void deleteAtBeginning(){
        if(!head){
            cout<<"The list is empty";
            return;
        }
        Node* temp = head;
        head = temp->next;
        free(temp);
    }

    void deleteAtEnd(){
        if(!head){
            cout<<"The list is empty";
            return;
        }
        if(!head->next){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = NULL;
        while(temp->next->next){
            temp = temp->next;
        }
        delete temp;
        temp->next = NULL;
    }

};


main(){
    SLinkedList list1;

    // Insert elements at the end
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    // Insert element at the beginning
    list1.insertAtBeginning(5);

    // Insert element at a specific position
    list1.insertAtPosition(15, 3);

    cout << "Linked list after insertions: ";
    list1.display();

    list1.deleteAtBeginning();

    list1.display();

    
    list1.deleteAtEnd();

    list1.display();

}