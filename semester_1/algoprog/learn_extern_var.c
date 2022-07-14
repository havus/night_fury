#include <stdio.h>

int main() {
  // HOW TO RUN:
  // $ cd semester_1/algoprog/
  // $ gcc learn_extern_var.c extern_var.c -o printer && ./printer && rm ./printer

  extern int x; // in extern_var.c
  // multiple variable external with the same name will be error
  printf("x = %d\n", x);

  return 0;
}
