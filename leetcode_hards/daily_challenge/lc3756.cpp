#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  static constexpr int MOD = 1e9 + 7;

  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    int n = s.size();

    // Compressed string (non-zero digits only)
    vector<int> digits;

    // cnt[i] = number of non-zero digits seen up to index i
    vector<int> cnt(n);

    int nonZero = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        digits.push_back(s[i] - '0');
        nonZero++;
      }
      cnt[i] = nonZero;
    }

    int m = digits.size();

    // No non-zero digits at all.
    if (m == 0)
      return vector<int>(queries.size(), 0);

    vector<long long> prefixValue(m + 1, 0);
    vector<long long> prefixSum(m + 1, 0);
    vector<long long> pow10(m + 1, 1);

    for (int i = 1; i <= m; i++) {
      pow10[i] = (pow10[i - 1] * 10LL) % MOD;
    }

    for (int i = 0; i < m; i++) {
      prefixSum[i + 1] = prefixSum[i] + digits[i];

      prefixValue[i + 1] = (prefixValue[i] * 10LL + digits[i]) % MOD;
    }

    vector<int> ans;

    for (auto &q : queries) {

      int l = q[0];
      int r = q[1];

      // First non-zero digit inside [l,r]
      int leftCompressed = (l == 0 ? 0 : cnt[l - 1]);

      // Last non-zero digit inside [l,r]
      int rightCompressed = cnt[r] - 1;

      // No non-zero digit in this query.
      if (leftCompressed > rightCompressed) {
        ans.push_back(0);
        continue;
      }

      int len = rightCompressed - leftCompressed + 1;

      long long digitSum =
          prefixSum[rightCompressed + 1] - prefixSum[leftCompressed];

      long long value = (prefixValue[rightCompressed + 1] -
                         prefixValue[leftCompressed] * pow10[len] % MOD + MOD) %
                        MOD;

      ans.push_back((value * digitSum) % MOD);
    }

    return ans;
  }
};
