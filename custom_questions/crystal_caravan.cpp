#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> checkpoints(n);
  for (int i = 0; i < n; i++) {
    std::cin >> checkpoints[i];
  }

  int noDeletion = checkpoints[0];
  int oneDeletion = 0;
  int ans = checkpoints[0];

  for (int i = 1; i < n; i++) {
    oneDeletion = std::max(checkpoints[i] + oneDeletion, noDeletion);
    noDeletion = std::max(checkpoints[i], noDeletion + checkpoints[i]);
    ans = std::max({oneDeletion, noDeletion, ans});
  }

  std::cout << ans;
  return 0;
}
