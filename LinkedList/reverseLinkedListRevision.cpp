#include <iostream>

struct Node {
  int data;
  Node *next;
};
class LinkedList {
  Node *head;
  int m_count = 0;

public:
  LinkedList() { head = nullptr; }
  void insertValue(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    m_count++;
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
  void read() {
    Node *temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
  }
  void reverse() {
    Node *next = nullptr;
    Node *prev = nullptr;
    Node *curr = head;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
};

int main() {
  int n, data;
  LinkedList list;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> data;
    list.insertValue(data);
  }
  list.read();
}
