#include <stdio.h>

void main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4};
  int *p_arr = arr;
  for (int i = 0; i < 4; i++) {
    printf("\n%d\n", *(p_arr + i));
  }
}
