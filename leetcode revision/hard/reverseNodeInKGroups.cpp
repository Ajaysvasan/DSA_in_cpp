#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *prev, ListNode *next) {
    ListNode *last = prev->next;
    ListNode *curr = last->next;
    while (curr != next) {
      last->next = curr->next;
      curr->next = prev->next;
      prev->next = curr;
      curr = last->next;
    }
    return last;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == NULL || k <= 1)
      return head;
    ListNode *dummy = new ListNode(0);
    ListNode *prev = dummy;
    ListNode *curr = head;
    ListNode *next = NULL;
    dummy->next = head;
    int count = 0;
    while (curr) {
      count++;
      if (count % k == 0) {
        next = curr->next;
        prev = reverse(prev, next);
        curr = prev->next;
      } else {
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};
