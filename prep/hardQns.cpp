#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countValues(vector<ll> &A, ll X, ll m) {
  ll total = 0;

  for (ll a : A) {
    if (a >= X) {
      total += (a - X + 1);
      if (total >= m)
        return total; // early stop
    }
  }

  return total;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;

  vector<ll> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  ll low = 0, high = 1e9, X = 0;

  // Binary Search
  while (low <= high) {
    ll mid = (low + high) / 2;

    if (countValues(A, mid, m) >= m) {
      X = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  ll total_sum = 0;
  ll total_count = 0;

  for (ll a : A) {
    if (a >= X) {
      ll k = a - X + 1;

      // AP sum
      total_sum += k * (a + X) / 2;
      total_count += k;
    }
  }

  // remove extra values
  if (total_count > m) {
    total_sum -= (total_count - m) * X;
  }

  cout << total_sum << endl;
}
