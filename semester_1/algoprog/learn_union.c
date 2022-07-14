#include <stdio.h>

union Person {
  unsigned char name[30];
  unsigned int  age;
};

union tbil {
  unsigned int di;
  unsigned char dc[3];
} bil_x;

void learnUnion1() {
  bil_x.di = 321;

  // 321 = 00000001 01000001
  // 01000001 = 65
  // 00000001 = 1

  // di, dc[0], dc[1] are shared memory
  printf("di    = %d\n", bil_x.di);     // di     = 321
  printf("dc[0] = %d\n", bil_x.dc[0]);  // dc[0]  = 65
  printf("dc[1] = %d\n", bil_x.dc[1]);  // dc[1]  = 1
  printf("dc[2] = %d\n", bil_x.dc[2]);  // dc[2]  = 0
}

struct biner {
  unsigned bit0: 1; unsigned bit1: 1;
  unsigned bit2: 1; unsigned bit3: 1;
  unsigned bit4: 1; unsigned bit5: 1;
  unsigned bit6: 1; unsigned bit7: 1;
};

union byte {
  unsigned char ch;
  struct biner bit;
};

void learnUnion2() {
  char          testCh    = 127; // char range from -128 to 127
  unsigned char testUnCh  = 130; // char range from 0 to 255

  printf("value testCh is %hhd\n", testCh);
  printf("value testUnCh is %hhd\n", testUnCh);
  // unsigned char
  // 127 = 127
  // 128 = -128
  // 129 = -127
  // 130 = -126
  // ...

  printf("sizeof char is %lu\n", sizeof(char)); // sizeof char is 1
  printf("sizeof unsigned char is %lu\n", sizeof(unsigned char)); // sizeof unsigned char is 1

  unsigned char ch;
  union byte x;

  printf("sizeof bil_x is %lu\n", sizeof(bil_x)); // sizeof bil_x is 4
  printf("sizeof x is %lu\n", sizeof(x)); // sizeof x is 4

  ch    = 100;
  x.ch  = ch;

  printf(
    "%d binary = %d%d%d%d%d%d%d%d\n",
    ch,
    x.bit.bit7, x.bit.bit6, x.bit.bit5, x.bit.bit4,
    x.bit.bit3, x.bit.bit2, x.bit.bit1, x.bit.bit0
  );
}

int main() {
  // learnUnion1();
  learnUnion2();

  return 0;
}
