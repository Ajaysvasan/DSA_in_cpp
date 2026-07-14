#include <stdio.h>
char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
// quiz  test , MCq , GeksQuiz
char **cp[] = {c + 3, c + 2, c + 1, c};
// quiz
char ***cpp = cp;
int main() {
  // test
  printf("%s ", **++cpp);
  // test
  printf("%s ", *--*++cpp + 3);
  // mcq
  printf("%s ", *cpp[-2] + 3);
  // test
  printf("%s ", cpp[-1][-1] + 1);
  return 0;
}
