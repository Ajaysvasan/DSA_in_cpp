struct ListNode {
  int data;
  ListNode *next;
};

class Solution {
public:
  ListNode *reverseList(ListNode *list, int left, int right) {
    if (!head->next || left == right)
      return head;
    ListNode *dummy = new ListNode(0);
    ListNode *prev = dummy;
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }
    ListNode *p = prev, *q = prev->next;
    ListNode *curr = q;
    for (int i = 0; i < right - left + 1; i++) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = t;
    }
    p->next = prev;
    q->next = curr;
    return dummy->next;
  }
};
