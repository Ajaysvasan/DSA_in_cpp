#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int strongPasswordChecker(string password) {
    if (password.size() < 6)
      return 6 - password.size();
  }
};
