#include <stdio.h>
#define SIZE(arr) sizeof(arr) / sizeof(*arr) // macros
void fun(int *arr, int n) {
  int i;
  // index 2 - > 30 + 10  = 40
  // 10 + 40 = 50
  *arr += *(arr + n - 1) += 10;
}
void printArr(int *arr, int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d ", arr[i]);
}
int main() {
  int arr[] = {10, 20, 30};
  int size = SIZE(arr);
  // 3

  fun(arr, size);
  printArr(arr, size);
  return 0;
}
