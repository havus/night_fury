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

void changeValue(int *num) {
  printf("value num=%d\n", *num);
  *num = (*num) + 1;
}

void learnPointerToPointer2() {
  int num = 9;
  int *pointer; 
  pointer = &num;

  printf("value num is: %d, address is: %p\n", num, &num);
  // address is different
  printf("value pointer is: %d, address is: %p\n", *pointer, &pointer);

  changeValue(pointer);
  printf("value num changed=%d\n", *pointer);
}

int main() {
  // learnPointerToPointer();
  learnPointerToPointer2();
}
