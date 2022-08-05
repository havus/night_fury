#include <stdio.h>
#include <string.h>

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

void learnpointerandarray() {
  int a[] = { 1, 3, 5, 7, 9 };
  printf("%p\n", a);
  printf("%p\n", &a[0]);
  printf("%d\n", a[0]);
  printf("%d\n", *a);
  printf("%d\n", *(&a[0]+3)); // &a[0] address of index 0
  // OUTPUT:
  // -1079271776
  // -1079271776
  // 1
  // 1
  // 7

  // with loop
  for (int i = 0; i < 5; i++) {
    printf("address = %p\n", &a[i]);
    printf("address = %p\n", a+i);
    printf("next address = %p\n", a+i);
    printf("value = %d\n", a[i]);
    printf("value = %d\n", *(a+i));
    printf("next value = %d\n", *(&a[i]+1));
    printf("================\n");
  }
}

void learnarrayofchar() {
  char c[8];
  c[0] = 'j';
  c[1] = 'o';
  c[2] = 'h';
  c[3] = 'n';

  printf("%s\n", c);
  printf("length=%lu\n", strlen(c));

  c[4] = '\0'; // without this we will got garbage value
  printf("length=%lu\n", strlen(c));
}

int main() {
  // learnPointerToPointer();
  // learnPointerToPointer2();
  // learnpointerandarray();
  learnarrayofchar();
}
