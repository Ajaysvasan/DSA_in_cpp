#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll n, m;
vector<ll> v, d;

ll countMeals(ll T) {
  ll total = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] >= T) {
      ll k = (v[i] - T) / d[i] + 1;
      total += k;
    }
  }
  return total;
}

int main() {
  cin >> n;
  cin >> m;

  v.resize(n);
  d.resize(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    cin >> d[i];

  ll left = 0, right = 1e18;

  while (left < right) {
    ll mid = (left + right + 1) / 2;

    if (countMeals(mid) >= m)
      left = mid;
    else
      right = mid - 1;
  }

  ll T = left;

  ll totalMeals = 0;
  ll answer = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] >= T) {
      ll k = (v[i] - T) / d[i] + 1;
      totalMeals += k;

      ll last = v[i] - (k - 1) * d[i];
      answer += k * (v[i] + last) / 2;
    }
  }

  if (totalMeals > m) {
    answer -= (totalMeals - m) * T;
  }

  cout << answer << endl;
}
