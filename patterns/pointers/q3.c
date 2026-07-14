#include <stdio.h>
void dynamic(int s, ...) { printf("%d ", s); }
int main() {
  dynamic(2, 4, 6, 8);
  dynamic(3, 6, 9);
  return 0;
}
