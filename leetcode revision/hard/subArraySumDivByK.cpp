#include <unordered_map>
#include <vector>

int subarraysDivByK(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> freq;
  freq[0] = 1; // prefix sum = 0 initially

  int prefix = 0;
  int result = 0;

  for (int x : nums) {
    prefix += x;
    int rem = prefix % k;

    if (rem < 0)
      rem += k; // normalize negative mod

    if (freq.count(rem)) {
      result += freq[rem];
    }

    freq[rem]++;
  }

  return result;
}
