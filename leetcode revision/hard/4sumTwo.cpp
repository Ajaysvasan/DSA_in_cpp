#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                 vector<int> &D) {
  int count = 0;
  unordered_map<int, int> mpp;
  for (int a : A) {
    for (int b : B) {
      mpp[a + b]++;
    }
  }
  for (int c : C) {
    for (int d : D) {
      int sum = -(c + d);
      if (mpp.count(sum)) {
        count += mpp[sum];
      }
    }
  }
  return count;
}
