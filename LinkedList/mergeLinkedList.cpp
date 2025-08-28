#include <iostream>

struct LinkedList {
  int data;
  LinkedList *next;
};

class Solution {
public:
  LinkedList *mergeUsingRecursion(LinkedList *l1, LinkedList *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;
    if (l1->data <= l2->data) {
      l1->next = mergeUsingRecursion(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeUsingRecursion(l1, l2->next);
      return l2;
    }
  }
  LinkedList *mergeUsingIteration(LinkedList *l1, LinkedList *l2) {
    LinkedList *dummy = new LinkedList();
    LinkedList *curr = dummy;
    while (l1 && l2) {
      if (l1->data <= l2->data) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy->next;
  }
};
