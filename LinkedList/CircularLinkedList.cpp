#include <iostream>

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

int main() {
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

    return 0;
}
