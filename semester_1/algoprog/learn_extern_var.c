#include <stdio.h>

int main() {
  // HOW TO RUN:
  // gcc -o printer semester_1/algoprog/learn_extern_var.c semester_1/algoprog/extern_var.c && ./printer && rm ./printer

  extern int x; // in extern_var.c
  // multiple variable external with the same name will be error
  printf("x = %d\n", x);
  // printf("y = %d\n", y); // will return error

  return 0;
}
