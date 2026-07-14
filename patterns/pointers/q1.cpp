#include <stdio.h>
int main() {
  int i, j, var = 'A';
  for (i = 5; i >= 1; i--) {
    for (j = 0; j < i; j++)
      printf("%c ", (var + j));
    printf("\n");
  }
  /*a b c d e
   * a b c d
   * a b c
   * a b
   * a*/

  return 0;
}
