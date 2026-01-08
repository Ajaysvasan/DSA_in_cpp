#include <algorithm>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;

    for (int a : asteroids) {
      bool destroyed = false;

      while (!st.empty() && st.top() > 0 && a < 0) {
        if (abs(st.top()) < abs(a)) {
          st.pop(); // stack asteroid explodes
          continue;
        } else if (abs(st.top()) == abs(a)) {
          st.pop(); // both explode
          destroyed = true;
          break;
        } else {
          destroyed = true; // current asteroid explodes
          break;
        }
      }

      if (!destroyed) {
        st.push(a);
      }
    }

    vector<int> res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
