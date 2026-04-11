#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> primeSubSequence(int start, int targetSum) {
    vector<int> primes = generatePrimes(start, targetSum);
    int n = primes.size();

    // dp[j] stores all combinations that sum up to j
    vector<vector<vector<int>>> dp(targetSum + 1);

    // Base case: To get a sum of 0, we use an empty set
    dp[0].push_back({});

    for (int p : primes) {
      // Iterate backwards to avoid using the same prime multiple times
      for (int j = targetSum; j >= p; j--) {
        for (auto prev_seq : dp[j - p]) {
          prev_seq.push_back(p);
          dp[j].push_back(prev_seq);
        }
      }
    }

    return dp[targetSum];
  }

private:
  vector<int> generatePrimes(int start, int end) {
    if (end < 2)
      return {};
    vector<bool> isPrime(end + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= end; p++) {
      if (isPrime[p]) {
        for (int i = p * p; i <= end; i += p)
          isPrime[i] = false;
      }
    }
    vector<int> res;
    for (int p = max(2, start); p <= end; p++) {
      if (isPrime[p])
        res.push_back(p);
    }
    return res;
  }
};

int main() {
  Solution s;
  auto res = s.primeSubSequence(7, 50);
  cout << "Found " << res.size() << " combinations." << endl;
  for (auto &seq : res) {
    for (int prime : seq) {
      cout << prime << " ";
    }
    cout << endl;
  }
  return 0;
}
