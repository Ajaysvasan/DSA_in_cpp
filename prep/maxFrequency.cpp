#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int left = 0;
    long long sum = 0;
    int ans = 1;
    for (int right = 0; right < arr.size(); right++) {
      sum += arr[right];
      while ((long long)arr[right] * (right - left + 1) - sum < k) {
        sum -= arr[left];
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 0;
  Solution s;
  cout << s.maxFrequency(arr, k);
}
