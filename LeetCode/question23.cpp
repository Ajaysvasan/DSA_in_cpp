/*Given an array of size n find all the elements that appear more than floor(n /
 * 3) times Input: nums = [3,2,3] Output: [3]
 *
 * Here n = 3 and the element 3 has appeared more than n / 3 times
 *
 * The better solution has Space compexity of O(n)
 *
 *  */
#include <iostream>
#include <map>
#include <vector>

std::vector<int> btrMajorityElement(std::vector<int> &nums) {
  std::vector<int> res;
  // Keeps the frequency of each elements
  std::map<int, int> mpp;

  for (int element : nums) {
    mpp[element] += 1;
  }
  for (const auto &[element, freq] : mpp) {
    if (freq > (nums.size()) / 3) {
      res.push_back(element);
    }
  }
  return res;
}

std::vector<int> optMajorityElement(std::vector<int> &nums) {
  std::vector<int> res;

  return res;
}

int main() {
  std::vector<int> nums = {3, 2, 3};
  std::vector<int> res = btrMajorityElement(nums);
  for (int element : res) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
  return 0;
}
