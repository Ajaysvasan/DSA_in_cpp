#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
int main() {
  int N, Q;
  std::cin >> N >> Q;
  std::unordered_map<int, int> tuple;
  for (int i = 0; i < N; i++) {
    int temp;
    std::cin >> temp;
    tuple[i + 1] = temp;
  }
  std::vector<int> res;
  int i = 0;
  while (i < Q) {
    std::unordered_map<int, int> temp = tuple;
    int MIN = INT_MAX;
    int K;
    std::cin >> K;
    while (K > 0) {
      int rm;
      std::cin >> rm;
      temp.erase(rm);
      K--;
    }
    for (const auto &[key, value] : temp) {
      if (value <= MIN) {
        MIN = value;
      }
    }
    res.push_back(MIN);
    i++;
  }
  for (int value : res) {
    std::cout << value << std::endl;
  }
}
