#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  std::vector<int> arr = {16, 17, 4, 3, 5, 2};
  std::vector<int> ans;
  for (int i = 0; i < arr.size(); i++) {
    int rightGreater = -1;
    for (int j = i + 1; j < arr.size(); j++) {
      if (rightGreater < arr[j]) {
        rightGreater = arr[j];
      }
    }
    ans.push_back(rightGreater);
  }
  for (int num : ans) {
    std::cout << num << " ";
  }
  return 0;
}
