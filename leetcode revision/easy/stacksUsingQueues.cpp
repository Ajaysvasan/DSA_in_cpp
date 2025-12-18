#include <deque>
using namespace std;
class Mystack {
public:
  deque<int> q;
  Mystack() {}
  void push(int data) { q.push_back(data); }
  int pop() {
    int val = q.back();
    q.pop_back();
    return val;
  }
  int top() { return q.back(); }
  bool empty() { return q.empty(); }
};
