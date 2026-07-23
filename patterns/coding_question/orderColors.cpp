#include <iostream>
#include <utility>
#include <vector>

//
// 0 , 1 , 2
// left = 0 , mid = 0 , right = n - 1
//  nums[mid] == 0
//  swap(nums[mid] , nums[left])
// left++ , mid++
// nums[mid] == 1
// mid++
// nums[mid] == 2
// swap(nums[right] , nums[mid])
// right--

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> colors(n);
  for (int i = 0; i < n; i++) {
    std::cin >> colors[i];
  }

  int left = 0, right = colors.size() - 1, mid = 0;
  while (mid <= right) {
    if (colors[mid] == 0) {
      std::swap(colors[mid], colors[left]);
      left++;
      mid++;
    } else if (colors[mid] == 2) {
      std::swap(colors[mid], colors[right]);
      right--;
    } else {
      mid++;
    }
  }

  for (int color : colors) {
    std::cout << color << " ";
  }

  return 0;
}
