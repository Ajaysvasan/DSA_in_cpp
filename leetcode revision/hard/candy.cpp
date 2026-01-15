#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int total_candies = n;
    int i = 1;
    while (i < n) {
      if (ratings[i] == ratings[i - 1]) {
        i++;
        continue;
      }

      int current_peak = 0;
      while (i < n && ratings[i] > ratings[i - 1]) {
        current_peak++;
        total_candies += current_peak;
        i++;
      }
      if (i == n) {
        return total_candies;
      }
      int current_valey = 0;
      while (i < n && ratings[i] < ratings[i - 1]) {
        current_valey++;
        total_candies += current_valey;
        i++;
      }
      total_candies -= min(current_valey, current_peak);
    }

    return total_candies;
  }
};

int main() {
  vector<int> ratings = {1, 2, 2};
  Solution s;
  cout << s.candy(ratings);
  return 0;
}
