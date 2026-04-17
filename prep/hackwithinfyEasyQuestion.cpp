#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;

  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int noQueries;
  cin >> noQueries;

  int sum = 0;
  for (int i = 0; i < noQueries; i++) {
    int type, l, r;
    cin >> type >> l >> r;
    cout << "Type " << type << "for query " << i + 1 << endl;
    switch (type) {
    case 1:
      for (int k = l; k <= r; k++) {
        arr[k] = (k - l + 1) * arr[l];
      }
      for (int value : arr) {
        cout << value << " ";
      }
      cout << endl;
      break;
    case 2:
      for (int j = l; j <= r; j++) {
        cout << arr[j];
        sum += arr[j];
      }
      cout << "Current sum : " << sum << endl;
      ;
      break;
    }
  }
  cout << sum << endl;
}
