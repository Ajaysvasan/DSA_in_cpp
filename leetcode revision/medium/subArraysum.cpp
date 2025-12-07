#include <unordered_map>
#include <vector>
using namespace std;
int subarraySum(vector<int> &nums, int k) {
  unordered_map<int, int> prefixCount;
  prefixCount[0] = 1; // important base case

  int sum = 0;
  int count = 0;

  for (int num : nums) {
    sum += num;

    if (prefixCount.find(sum - k) != prefixCount.end()) {
      count += prefixCount[sum - k];
    }

    prefixCount[sum]++;
  }

  return count;
}
