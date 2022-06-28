// ref: https://home.csulb.edu/~pnguyen/cecs282/lecnotes/Pointer.pdf

#include <stdio.h>

void learnBlankVariable() {
  char  varChar;
  int   varInt;

  if (varChar) {
    printf("varChar is present\n");
  }

  if (varInt) {
    printf("varInt is present\n");
  }

  // note: declare a variable without value -> it has a default value = 0
}

void learnAddress() {
  char    varChar;
  char    *varChar2;

  int     varInt;
  int     *varInt2;

  double  varDouble;
  double  *varDouble2;

  printf("Value of varInt is %d in %p \n", varInt, &varInt);
  // output: Value of varInt is -901004327, with address 0x7ffeef32bf7c

  printf("Value of varInt2 is %d in %p and %p \n", *varInt2, &(varInt2), varInt2);
  // output: Value of varInt2 is -281886192 in 0x7ffeef32bf70 and 0x7ffeef32bfd0

  printf("Value of varInt is %d in %p, and varInt2 is %d in %p \n", varInt, &varInt, *varInt2, varInt2);
  // output: Value of varInt is -901004327 in 0x7ffeef32bf7c, and varInt2 is -281886192 in 0x7ffeef32bfd0

  varInt2 = &varInt;

  printf("Value of varInt is %d in %p, and varInt2 is %d in %p \n", varInt, &varInt, *varInt2, varInt2);
  // output: Value of varInt is -779816433, and varInt2 is -779816433

  varInt  = 107;
  printf("Value of varInt is %d, and varInt2 is %d\n", varInt, *varInt2);
  // output: Value of varInt is 107, and varInt2 is 107
}

void learnDereferencing1() {
  int a;
  int *p;

  a = 7;
  p = &a;

  printf("a = %d\n", a);

  *p = 10;
  printf("a = %d\n", a);
}

void learnDereferencing2() {
  int a;
  int *p;

  a = 7;
  p = &a; // &a = address of a

  printf("a = %d, address a = %p\n", a, &a); // a = 7, address a = 0x7ffeec40cf8c
  printf("p = %d, address p = %p\n", *p, p); // p = 7, address p = 0x7ffeec40cf8c

  int b = 33;
  *p = b;

  printf("p = %d, address p = %p\n", *p, p); // p = 33, address p = 0x7ffeec40cf8c
  // b value is an integer, NOT an address
}

void learnPointerDeclaration() {
  // ===================== WAY 1 - START =====================
  // int a = 10;
  // int *p = &a;
  // printf("a = %d, address a = %p\n", a, &a); // a = 7, address a = 0x7ffeee9fbf8c
  // ===================== WAY 1 - END =====================


  // ===================== WAY 2 - START =====================
  int a = 10;
  int *p;
  p = &a;
  // printf("a = %d, address a = %p\n", a, &a); // a = 7, address a = 0x7ffeee9fbf8c
  // ===================== WAY 2 - END =====================
  // NOTE: way 1 and 2 is same declaration pointer

  printf("address p = %p\n", p); // a = 7, address a = 0x7ffeee9fbf8c
}

void learnPointerType() {
  int a   = 1025;
  int *p  = &a;

  printf("size of integer is %lu bytes\n", sizeof(int));
  printf("address p = %p, value = %d\n", p, *p);

  char *p0;
  p0 = (char*)p; // typecasting

  printf("size of integer is %lu bytes\n", sizeof(char));
  printf("address p0 = %p, value = %d\n", p0, *p0);

  // if a = 1025
  // 1025 to binary is 10000000001 (Binary signed 2's complement)=> 00000100 00000001
  // and get the first byte => 00000001 (convert to decimal)=> 1
  // 1025 / 2 => 512  => sisa 1
  // 512  / 2 => 256  => sisa 0
  // 256  / 2 => 128  => sisa 0
  // 128  / 2 => 64   => sisa 0
  // 64   / 2 => 32   => sisa 0
  // 32   / 2 => 16   => sisa 0
  // 16   / 2 => 8    => sisa 0
  // 8    / 2 => 4    => sisa 0
  // 4    / 2 => 2    => sisa 0
  // 2    / 2 => 1    => sisa 0
  // 1    / 2 => 0    => sisa 1
  // result diambil dari bawah: 10000000001
  // ____________________ if a = 1026 ____________________
  // 1026 to binary is 10000000010 (Binary signed 2's complement)=> 00000100 00000010
  // and get the first byte => 00000010 (convert to decimal)=> 2

  printf("address p0 = %p, value = %d\n", p0 + 1, *(p0 + 1));
  // address p0 = 0x7ffee8639f8d, value = 4
  // why 4??? WTF
  // 1025 = 00000100 00000001
  //        byte_2   byte_1
  // +1 = ngambil byte yg ke-2 => 00000100 => 4
}

void learnVoidPointer() {
  int a   = 1025;
  int *p  = &a;

  printf("size of integer is %lu bytes\n", sizeof(int));
  printf("address p = %p, value = %d\n", p, *p);

  // void pointer - generic pointer
  void *p0;
  p0 = p;

  printf("size of void is %lu bytes\n", sizeof(void));
  // printf("address p0 = %p, value = %d\n", p0, *p0);
  printf("address p0 = %p, value can NOT printed cause nothing inside there\n", p0);
}

int main() {
  puts("It's time to learn pointer!");

  // learnBlankVariable();
  // learnAddress();
  // learnDereferencing1();
  // learnDereferencing2();
  // learnPointerDeclaration();
  // learnPointerType();
  learnVoidPointer();

  return 0;
}
