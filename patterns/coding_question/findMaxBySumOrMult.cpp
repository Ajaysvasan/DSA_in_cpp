#include <iostream>
#include <vector>

using namespace std;

int sum(int num) {
  int total = 0;
  while (num > 0) {
    total += (num % 10);
    num /= 10;
  }
  return total;
}

int mult(int num) {
  constexpr int mod = 1e9 + 7;
  int total = 1;
  while (num > 0) {
    total = (total * (num % 10)) % mod;
    num /= 10;
  }
  return total % mod;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<int> res;
  for (int num : nums) {
    int current_sum = sum(num);
    int current_mult = mult(num);
    res.push_back(max(current_sum, current_mult));
  }
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}
