#include <climits>
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k) {
  double result = INT_MIN;
  int left = 0, sum = 0;
  for (int right = 0; right < nums.size(); right++) {
    sum += nums[right];
    while (right - left + 1 > k) {
      sum -= nums[left];
      left++;
    }
    if (right - left + 1 == k) {
      double avg = (double)sum / k;
      result = max(result, avg);
    }
  }
  return result;
}
