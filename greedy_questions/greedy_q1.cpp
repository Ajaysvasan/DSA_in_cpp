#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int bestTimeToSellStocks2(vector<int> &stocks) {
  int profit = 0;
  for (int i = 1; i < stocks.size(); i++) {
    if (stocks[i] > stocks[i - 1])
      profit += stocks[i] - stocks[i - 1];
  }
  return profit;
}
int main(int argc, char *argv[]) {
  vector<int> stocks = {7, 1, 5, 3, 6, 4};
  cout << bestTimeToSellStocks2(stocks);

  return 0;
}
