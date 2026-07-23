#include <algorithm>
#include <iostream>

using namespace std;

struct Rectangle {
  int xmin, ymin;
  int xmax, ymax;
};

int main() {

  Rectangle r1, r2;

  cin >> r1.xmin >> r1.ymin >> r1.xmax >> r1.ymax;
  cin >> r2.xmin >> r2.ymin >> r2.xmax >> r2.ymax;

  int left = max(r1.xmin, r2.xmin);
  int right = min(r1.xmax, r2.xmax);
  int bottom = max(r1.ymin, r2.ymin);
  int top = min(r1.ymax, r2.ymax);

  if (left >= right || bottom >= top) {
    cout << "No Intersection";
    return 0;
  }

  cout << "(" << left << "," << bottom << ")" << endl;
  cout << "(" << right << "," << bottom << ")" << endl;
  cout << "(" << right << "," << top << ")" << endl;
  cout << "(" << left << "," << top << ")" << endl;

  return 0;
}
