#include <iostream>

struct Node {
  int data;
  Node *next;
};

class LinkedList {
  int m_count = 0;
  Node *head;

public:
  LinkedList() { head = nullptr; }
  void insertValue(int data) {
    Node *new_node = new Node();
    m_count++;
    new_node->data = data;
    new_node->next = nullptr;
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

  void reverseKGroup(int k) {
    if (!head || k == 1) {
      return;
    }
    Node dummy;
    dummy.next = head;
    Node *prevGroup = &dummy;
    while (true) {
      Node *kth = prevGroup;
      for (int i = 0; i < k && kth; i++) {
        kth = kth->next;
      }
      if (!kth) {
        break;
      }
      Node *startGroup = prevGroup->next;
      Node *nextGroup = kth->next;
      Node *prev = nextGroup;
      Node *curr = startGroup;
      while (curr != nextGroup) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      }

      prevGroup->next = kth;
      prevGroup = startGroup;
    }
    head = dummy.next;
  }

  void diplay() {
    Node *temp = head;
    std::cout << "the list values are \n";
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
  void deleteData() {
    if (head == nullptr || head->next == nullptr) {
      head = nullptr;
      return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nullptr;
  }
  void reverse() {
    Node *curr = head;
    Node *next = nullptr;
    Node *prev = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
  ~LinkedList() {
    while (head != nullptr) {
      deleteData();
    }
  }
};
int main() {
  int n = 10;
  LinkedList list;
  for (int i = 0; i < n; i++) {
    int data;
    std::cin >> data;
    list.insertValue(data);
  }
  // list.reverse();
  list.reverseKGroup(2);
  list.diplay();
}
