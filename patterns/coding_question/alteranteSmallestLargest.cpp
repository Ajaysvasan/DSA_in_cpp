#include <algorithm>
#include <iostream>
#include <vector>
// 25.   Given an array of integers, write a program to re-arrange the array in
// the given form. 1st_largest, 1st_smallest, 2nd_largest, 2nd_smallest,
// 3rd_largest ……. etc.
using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  int left = 0, right = n - 1;
  while (left <= right) {
    if (left == right) {
      res.push_back(nums[right]);
      break;
    }
    res.push_back(nums[right]);
    res.push_back(nums[left]);
    left++;
    right--;
  }
  for (int num : res) {
    cout << num << " ";
  }

  return 0;
}
