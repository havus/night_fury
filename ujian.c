#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  // int n = 5;

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (i == 0 || i == n-1) {
  //       printf("* ");
  //       continue;
  //     }

  //     if (j == 0 || j == n-1) {
  //       printf("* ");
  //     } else {
  //       printf("  ");
  //     }
  //   }
  //   printf("\n");
  // }

  // ------------------------------------------------------------

  int result[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int index     = 7;
  int decimal   = 10; // this will be converted to hexadecimal
  // 10 / 2 = 5 sisa 0 => masukkan ke result paling akhir
  // 5  / 2 = 2 sisa 1
  // 2  / 2 = 1 sisa 0
  // 1  / 2 = 0 sisa 1

  // 1010 => 00001010
  int hasilBagi = decimal; // init value
  do {
    int modulo    = hasilBagi % 2;
    result[index] = modulo;
    hasilBagi     = hasilBagi / 2;

    index--; // decrease index for next input
  } while (hasilBagi != 0);

  printf("decimal: %d, hexadecimal: ", decimal);
  for (int i = 0; i < 8; i++) {
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}
