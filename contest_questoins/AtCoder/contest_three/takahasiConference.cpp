#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  if (!(std::cin >> n))
    return 0;

  std::vector<int> takahasiHeight(n);
  std::vector<int> leavingTime(n);

  for (int i = 0; i < n; i++) {
    std::cin >> takahasiHeight[i] >> leavingTime[i];
  }
  std::vector<int> maxHeight(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    maxHeight[i] = std::max(takahasiHeight[i], maxHeight[i + 1]);
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int t;
    std::cin >> t;
    auto it = upper_bound(leavingTime.begin(), leavingTime.end(), t);

    int left = distance(leavingTime.begin(), it);

    std::cout << maxHeight[left] << "\n";
  }

  return 0;
}
