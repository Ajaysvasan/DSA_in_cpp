#include <stdio.h>
int main() {
  char str[] = "Aptitude";
  printf("%s %s %s\n", &str[5], &5 [str], str + 3);
  printf("%c %c %c\n", *(str + 6), str[6], 6 [str]);
  return 0;
}
