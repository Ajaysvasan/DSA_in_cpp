#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Brute force
int sumMinSubArray(vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    int min = arr[i];
    for (int j = i; j < arr.size(); j++) {
      if (arr[j] >= min) {
        min = arr[j];
      }
      sum += min;
    }
  }
  return sum;
}

// Optimal
class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    vector<int> psc(n), nsc(n);
    stack<int> st;

    // Previous Smaller (strict)
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
      }
      psc[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    // Next Smaller or Equal
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }
      nsc[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    long long total = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
      long long left = i - psc[i];
      long long right = nsc[i] - i;
      total = (total + left * right % mod * arr[i]) % mod;
    }

    return total;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 4, 6, 7, 3, 7, 8, 1};
  int total = s.sumSubarrayMins(nums);
  cout << "Optimal answer: " << total
       << "\nBrute force solution: " << sumMinSubArray(nums);
  return 0;
}
