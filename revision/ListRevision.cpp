#include<iostream>

class SingleLinkedList{
    private:
    int m_count = 0;

    struct Node{
            int data;
            Node *next;
        } *head;    
    public:
        SingleLinkedList(){
            head = nullptr;
        }

        void insert_at_begin(int data){
                Node* new_node = new Node();
                new_node->data = data;
                new_node->next = head;
                head = new_node;
                m_count++;
        }

        void insert_at_end(int data){
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = nullptr;
            if(!head){
                head = new_node;
                m_count++;
                return;
            }
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_node;
            m_count++;
        }

        void insert_at_pos(int data ,int pos){
            // pos -> 0 to n-1

            if(pos>m_count || pos < 0){
                std::cout<<"Invalid input"<<std::endl;
                return;
            }

            if(pos == 0){
                insert_at_begin(data);
                return;
            }
                
            if(pos == m_count-1){
                insert_at_end(data);
                return;
            }
            Node* new_node = new Node();
            new_node->data = data;
            Node* temp = head;
            // list = 1 2 3 4 5 6 , pos = 3 
            for(int i = 0;i<pos-1;i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        
        void delete_at_begin(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            if(!head->next){
                free(head);
                head = nullptr;
                m_count--;
                return;
            }
            Node* temp = head;
            head = temp->next;
            free(temp);
            m_count--;
        }
        void delete_at_end(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            Node* temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            free(temp->next);
            temp->next = nullptr;
            m_count--;
        }

        void delete_at_pos(int pos){
            //pos -> 0 to n-1
            if(pos>m_count || pos < 0){
                std::cout<<"Invalid input"<<std::endl;
                return;
            }
            if(pos == 0){
                delete_at_begin();
                return;
            }
            if(pos == m_count-1){
                delete_at_end();
                return;
            }
            Node* temp = head;
            // List = [1 2 3 4 5 6 7 ], pos = 3
            for(int i = 0;i<pos-1;i++){
                temp = temp->next;
            }
            Node* del_address = temp->next;
            temp->next = temp->next->next;
            free(del_address);
            m_count--;
        }

        void search(int target){
            if(!head){
                std::cout<<"The List is empty"<<std::endl;
                return;
            }
            Node* temp = head;
            for(int i = 0;i<m_count && temp;i++){
                if(temp->data == target){
                    std::cout<<"Element is found at position "<<i<<std::endl;
                    return;
                }
                temp = temp->next;
            }
            std::cout<<"The element is not present in the list"<<std::endl;
        }
        
        void print(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            Node* temp = head;
            std::cout<<"Printig the List"<<std::endl;
            while(temp){
                std::cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            std::cout<<"NULL"<<std::endl;
        }

        ~SingleLinkedList(){
            Node* temp = head;
            while(head){
                delete_at_end();
            }
        }
};

class DoubleLinkedList{
    private:
        struct Node{
            int data;
            Node* next,*prev;
        }*head,*last;
        int m_count = 0;
    public:
        DoubleLinkedList(){
            head = nullptr;
            last = nullptr;
        }
        void insert_at_begin(int data){
            m_count++;
            Node* new_node = new Node();
            new_node->data = data;
            if(!head){
                new_node->next = nullptr;
                new_node->prev = nullptr;
                head = new_node;
                last = new_node;
                return;
            }
            new_node->next = head;
            new_node->prev = nullptr;
            head->prev = new_node;
            head = new_node;
        }
        void insert_at_end(int data){
            m_count++;
            Node* new_node = new Node();
            new_node->data = data;
            if(!head){
                new_node->next = nullptr;
                new_node->prev = nullptr;
                head = new_node;
                last = new_node;
                return;
            }
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            new_node->prev = temp;
            new_node->next = nullptr;
            last = new_node;
            temp->next = new_node;
        }
        void insert_at_pos(int data,int pos){
            // pos -> 0 to n

            if(pos>m_count || pos < 0){
                std::cout<<"Invalid input"<<std::endl;
                return;
                }
        
            if(pos == 0){
                 insert_at_begin(data);
                    return;
                }
                        
            if(pos == m_count){
                insert_at_end(data);
                    return;
                }
            m_count++;
            Node* new_node = new Node();
            new_node->data = data;
            Node* temp = head;
            for(int i = 0;i<pos-1;i++){
                temp = temp->next;
            } 
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next = new_node;
            if (new_node->next != nullptr)
                new_node->next->prev = new_node;
            else
                last = new_node;
        }

        void delete_at_begin(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            m_count--;
            if(!head->next){
                delete(head);
                head = nullptr;
                last = nullptr;
                return;
            }
            Node* temp = head;
            head = temp->next;
            head->prev = nullptr;
            delete(temp);
        }
        void delete_at_end(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            m_count--;
            if(head == last){
                delete last;
                head = last = nullptr;
                return;
            }
            Node* temp = last;
            last = last->prev;
            last->next = nullptr;
            delete(temp);
        }

        void delete_at_pos(int pos){
            if(pos>m_count || pos < 0){
                std::cout<<"Invalid input"<<std::endl;
                return;
            }
            if(pos == 0){
                delete_at_begin();
                return;
            }
            if(pos == m_count-1){
                delete_at_end();
                return;
            }
            m_count--;
            Node* temp = head;
            for(int i = 0;i<pos-1;i++){
                temp = temp->next;
            } 
            Node *del_address = temp->next;
            temp->next = del_address->next;
            del_address->next->prev = temp;
            delete(del_address);
        }

        void search_from_start(int target){
            std::cout<<"Search from begining"<<std::endl;
            if(!head){
                std::cout<<"The List is empty"<<std::endl;
                return;
            }
            Node* temp = head;
            for(int i = 0;i<m_count && temp;i++){
                if(temp->data == target){
                    std::cout<<"Element is found at position "<<i<<std::endl;
                    return;
                }
                temp = temp->next;
            }
            std::cout<<"The element is not present in the list"<<std::endl;
        }

        void search_from_end(int target){
            std::cout<<"Search From end"<<std::endl;
            if(!head){
                std::cout<<"The List is empty"<<std::endl;
                return;
            }
            Node* temp = last;
            int i = m_count - 1;
            while(temp){
                if(temp->data == target){
                    std::cout<<"Element is found at position "<<i<<std::endl;
                    return;
                }
                temp = temp->prev;
                i--;
            }
            std::cout<<"The element is not present in the list"<<std::endl;
        }

        void print(){
            if(!head){
                std::cout<<"The list is empty"<<std::endl;
                return;
            }
            Node* temp = head;
            std::cout<<"Printig the List"<<std::endl;
            while(temp){
                std::cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            std::cout<<"NULL"<<std::endl;
        }

        ~DoubleLinkedList(){
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            last = nullptr;
        }
};

class CircularLinkedList {
    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        } *head, *last;
    
        int m_count = 0;
    
    public:
        CircularLinkedList() : head(nullptr), last(nullptr) {}
    
        void insert_at_begin(int data) {
            Node* new_node = new Node{data, nullptr, nullptr};
            m_count++;
    
            if (!head) {
                head = last = new_node;
                new_node->next = new_node->prev = new_node;
            } else {
                new_node->next = head;
                new_node->prev = last;
                head->prev = new_node;
                last->next = new_node;
                head = new_node;
            }
        }
    
        void insert_at_end(int data) {
            Node* new_node = new Node{data, nullptr, nullptr};
            m_count++;
    
            if (!head) {
                head = last = new_node;
                new_node->next = new_node->prev = new_node;
            } else {
                new_node->next = head;
                new_node->prev = last;
                last->next = new_node;
                head->prev = new_node;
                last = new_node;
            }
        }
    
        void insert_at_pos(int data, int pos) {
            if (pos < 0 || pos > m_count) {
                std::cout << "Invalid input\n";
                return;
            }
    
            if (pos == 0) {
                insert_at_begin(data);
            } else if (pos == m_count) {
                insert_at_end(data);
            } else {
                m_count++;
                Node* temp = head;
                for (int i = 0; i < pos - 1; i++)
                    temp = temp->next;
    
                Node* new_node = new Node{data, temp->next, temp};
                temp->next->prev = new_node;
                temp->next = new_node;
            }
        }
    
        void delete_at_begin() {
            if (!head) {
                std::cout << "The list is empty\n";
                return;
            }
    
            m_count--;
            if (head == last) {
                delete head;
                head = last = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                last->next = head;
                head->prev = last;
                delete temp;
            }
        }
    
        void delete_at_end() {
            if (!head) {
                std::cout << "The list is empty\n";
                return;
            }
    
            m_count--;
            if (head == last) {
                delete last;
                head = last = nullptr;
            } else {
                Node* temp = last;
                last = last->prev;
                last->next = head;
                head->prev = last;
                delete temp;
            }
        }
    
        void delete_at_pos(int pos) {
            if (pos < 0 || pos >= m_count) {
                std::cout << "Invalid input\n";
                return;
            }
    
            if (pos == 0) {
                delete_at_begin();
            } else if (pos == m_count - 1) {
                delete_at_end();
            } else {
                m_count--;
                Node* temp = head;
                for (int i = 0; i < pos - 1; i++)
                    temp = temp->next;
    
                Node* del_node = temp->next;
                temp->next = del_node->next;
                del_node->next->prev = temp;
                delete del_node;
            }
        }
    
        void search_from_start(int target) {
            std::cout << "Search from beginning\n";
            if (!head) {
                std::cout << "The List is empty\n";
                return;
            }
    
            Node* temp = head;
            for (int i = 0; i < m_count; i++) {
                if (temp->data == target) {
                    std::cout << "Element is found at position " << i << std::endl;
                    return;
                }
                temp = temp->next;
            }
            std::cout << "The element is not present in the list\n";
        }
    
        void search_from_end(int target) {
            std::cout << "Search from end\n";
            if (!last) {
                std::cout << "The List is empty\n";
                return;
            }
    
            Node* temp = last;
            for (int i = m_count - 1; i >= 0; i--) {
                if (temp->data == target) {
                    std::cout << "Element is found at position " << i << std::endl;
                    return;
                }
                temp = temp->prev;
            }
            std::cout << "The element is not present in the list\n";
        }
    
        void print() {
            if (!head) {
                std::cout << "The list is empty\n";
                return;
            }
    
            Node* temp = head;
            std::cout << "Printing the List:\n";
            for (int i = 0; i < m_count; i++) {
                std::cout << temp->data;
                if (i < m_count - 1) std::cout << " <-> ";
                temp = temp->next;
            }
            std::cout << " -> (head)\n";
        }
    
        ~CircularLinkedList() {
            while (m_count)
                delete_at_begin();
        }
    };

main(){
    SingleLinkedList slist;
    slist.insert_at_begin(1);
    for(int i = 2;i<16;i++)
        slist.insert_at_end(i);
    slist.insert_at_pos(27,3);
    slist.print();

    slist.search(27);

    slist.delete_at_pos(0);
    slist.print();

    slist.delete_at_begin();
    slist.print();

    slist.delete_at_end();
    slist.print();

    DoubleLinkedList dlist;
    dlist.insert_at_begin(16);
    for(int i = 17;i<23;i++)
        dlist.insert_at_end(i);
    dlist.insert_at_pos(27,4);
    dlist.print();

    dlist.search_from_start(27);
    dlist.search_from_end(17);

    dlist.delete_at_pos(0);
    dlist.print();

    dlist.delete_at_begin();
    dlist.print();

    dlist.delete_at_end();
    dlist.print();

    CircularLinkedList clist;

    clist.insert_at_begin(1);
    for (int i = 2; i < 16; i++)
        clist.insert_at_end(i);

    clist.insert_at_pos(27, 3);
    clist.print();

    clist.search_from_start(27);
    clist.search_from_end(27);

    clist.delete_at_pos(0);
    clist.print();

    clist.delete_at_begin();
    clist.print();

    clist.delete_at_end();
    clist.print();

}