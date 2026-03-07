#include <iostream>
#include <vector>

class Solution {
public:
  void sol(std::vector<int> &inp, int &X) {
    for (int x : inp) {
      if (x < X) {
        X = x;
        std::cout << 1 << std::endl;
      } else {
        std::cout << 0 << std::endl;
      }
    }
  }
};
int main() {
  Solution s;
  int N, X;
  std::vector<int> inp;
  std::cin >> N >> X;
  for (int i = 0; i < N; i++) {
    int temp;
    std::cin >> temp;
    inp.push_back(temp);
  }
  s.sol(inp, X);
}
