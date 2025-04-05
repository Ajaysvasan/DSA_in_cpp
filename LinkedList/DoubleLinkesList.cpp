#include<iostream>
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


main(){
    DoubleLinkedList dlist;
    dlist.insert_at_begin(1);
    for(int i = 2;i<16;i++)
        dlist.insert_at_end(i);
    dlist.insert_at_pos(27,3);
    dlist.print();

    dlist.search_from_start(27);
    dlist.search_from_end(27);

    dlist.delete_at_pos(0);
    dlist.print();

    dlist.delete_at_begin();
    dlist.print();

    dlist.delete_at_end();
    dlist.print();

}