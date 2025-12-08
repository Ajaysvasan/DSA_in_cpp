#include <iostream>

class SingleLinkedList {
private:
  int m_count = 0;

  struct Node {
    int data;
    Node *next;
  } *head;

public:
  SingleLinkedList() { head = nullptr; }

  void insert_at_begin(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    m_count++;
  }

  void insert_at_end(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if (!head) {
      head = new_node;
      m_count++;
      return;
    }
    Node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_node;
    m_count++;
  }

  void insert_at_pos(int data, int pos) {
    // pos -> 0 to n-1

    if (pos > m_count || pos < 0) {
      std::cout << "Invalid input" << std::endl;
      return;
    }

    if (pos == 0) {
      insert_at_begin(data);
      return;
    }

    if (pos == m_count - 1) {
      insert_at_end(data);
      return;
    }
    Node *new_node = new Node();
    new_node->data = data;
    Node *temp = head;
    // list = 1 2 3 4 5 6 , pos = 3
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }

  void delete_at_begin() {
    if (!head) {
      std::cout << "The list is empty" << std::endl;
      return;
    }
    if (!head->next) {
      free(head);
      head = nullptr;
      m_count--;
      return;
    }
    Node *temp = head;
    head = temp->next;
    free(temp);
    m_count--;
  }
  void delete_at_end() {
    if (!head) {
      std::cout << "The list is empty" << std::endl;
      return;
    }
    Node *temp = head;
    while (temp->next->next) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    m_count--;
  }

  void delete_at_pos(int pos) {
    // pos -> 0 to n-1
    if (pos > m_count || pos < 0) {
      std::cout << "Invalid input" << std::endl;
      return;
    }
    if (pos == 0) {
      delete_at_begin();
      return;
    }
    if (pos == m_count - 1) {
      delete_at_end();
      return;
    }
    Node *temp = head;
    // List = [1 2 3 4 5 6 7 ], pos = 3
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    Node *del_address = temp->next;
    temp->next = temp->next->next;
    free(del_address);
    m_count--;
  }

  void search(int target) {
    if (!head) {
      std::cout << "The List is empty" << std::endl;
      return;
    }
    Node *temp = head;
    for (int i = 0; i < m_count && temp; i++) {
      if (temp->data == target) {
        std::cout << "Element is found at position " << i << std::endl;
        return;
      }
      temp = temp->next;
    }
    std::cout << "The element is not present in the list" << std::endl;
  }

  void print() {
    if (!head) {
      std::cout << "The list is empty" << std::endl;
      return;
    }
    Node *temp = head;
    std::cout << "Printig the List" << std::endl;
    while (temp) {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
  }

  void revere_using_endF() {
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *curr = head;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }

  ~SingleLinkedList() {
    Node *temp = head;
    while (head) {
      delete_at_end();
    }
    delete temp;
  }
};

int main() {
  SingleLinkedList slist;
  slist.insert_at_begin(1);
  for (int i = 2; i < 16; i++)
    slist.insert_at_end(i);
  slist.insert_at_pos(27, 3);
  slist.print();

  slist.search(27);

  slist.delete_at_pos(0);
  slist.print();

  slist.delete_at_begin();
  slist.print();

  slist.delete_at_end();
  slist.print();

  slist.revere_using_endF();
  slist.print();
}
