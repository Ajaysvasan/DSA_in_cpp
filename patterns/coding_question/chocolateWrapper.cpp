#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int initialMoney, pricePerChocolate, minWrappers, choco, maxVisit;

  cin >> initialMoney >> pricePerChocolate >> minWrappers >> choco >> maxVisit;

  int totalNumberOfChocolates = initialMoney / pricePerChocolate;
  int currentWrappers = totalNumberOfChocolates;
  int currVisit = 0;

  while (currentWrappers >= minWrappers &&
         (maxVisit == 0 || currVisit < maxVisit)) {
    int exchanges = currentWrappers / minWrappers;

    int newChocolates = exchanges * choco;

    totalNumberOfChocolates += newChocolates;

    currentWrappers = (currentWrappers % minWrappers) + newChocolates;

    currVisit++;
  }

  cout << "total chocolate can eat: " << totalNumberOfChocolates
       << "\nwrappers left in hand: " << currentWrappers;

  return 0;
}
