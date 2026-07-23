#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  std::vector<int> even;
  std::vector<int> odd;

  for (int num : nums) {
    if (num % 2 == 0) {
      even.push_back(num);
    } else {
      odd.push_back(num);
    }
  }

  std::sort(even.begin(), even.end());
  std::sort(odd.begin(), odd.end());
  std::vector<int> res;
  int even_idx = 0, odd_idx = odd.size() - 1;
  while (even_idx < even.size() && odd_idx >= 0) {
    res.push_back(even[even_idx]);
    even_idx++;
    res.push_back(odd[odd_idx]);
    odd_idx--;
  }
  while (even_idx < even.size()) {
    res.push_back(even[even_idx]);
    even_idx++;
  }
  while (odd_idx >= 0) {
    res.push_back(odd[odd_idx]);
    odd_idx--;
  }
  for (int num : res) {
    std::cout << num << " ";
  }
  return 0;
}
