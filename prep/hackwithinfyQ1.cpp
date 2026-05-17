#include <bits/stdc++.h>
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
int foodStamp() {
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
  return answer;
}
#include <bits/stdc++.h>

int main() {
  // Heap solution
  int n;
  ll m;
  cin >> n >> m;

  vector<ll> v(n), d(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    cin >> d[i];

  // max heap: (current_value, decrement)
  priority_queue<pair<ll, ll>> pq;

  for (int i = 0; i < n; i++) {
    pq.push({v[i], d[i]});
  }

  ll ans = 0;

  while (m-- && !pq.empty()) {
    auto [val, dec] = pq.top();

    pq.pop();
    if (val <= 0)
      break;

    ans += val;

    ll next = val - dec;
    if (next > 0) {
      pq.push({next, dec});
    }
  }

  cout << ans << endl;
  // Binary search solution
  foodStamp();
}
