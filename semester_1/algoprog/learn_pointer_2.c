#include <stdio.h>

void learnPointerToPointer() {
  int x   = 5;
  int* p  = &x;
  // p = &x;
  *p = 6;

  printf("value x = %d\n", x);
  printf("value p = %d\n", *p);
  
  printf("=================\n");
  // int** q = &x; // incompatible pointer types initializing 'int **' with an expression of type 'int *'
  int** q   = &p;
  int*** r  = &q;
  printf("value x = %d\n", x);
  printf("value p = %d\n", *p);
  printf("value q = %d\n", **q); // **q == *(*q)
  printf("value q = %d\n", *(*(*r))); // with parentheses is better

  printf("======= ***r = **q + 10; ==========\n");
  ***r = **q + 10;
  printf("value x = %d\n", x);
}

int main() {
  learnPointerToPointer();
}
