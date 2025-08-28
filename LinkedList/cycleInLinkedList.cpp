struct LinkedList{
  int data;
  LinkedList* next;
};

class Solution{
public:
  bool cycle(LinkedList* list){
    LinkedList* slow = list;
    LinkedList* fast = list->next;
    while(fast != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){
        return true;
      }
    }
    return false;
  }
};
