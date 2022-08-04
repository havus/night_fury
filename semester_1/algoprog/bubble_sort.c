#include <stdio.h>

int main() {
  int list[5] = {10, 4, 7, 9, 5};
  int sizeList = 5;

  int swaped = 0;

  do {
    printf(".");
    swaped = 0;

    for (int i = 0; i <= sizeList - 1; i++) {
      if (i == sizeList - 1) { // dont have next el
        continue;
      }

      int nextEl = list[i+1];
      int currentEl = list[i];

      // swap
      if (currentEl > nextEl) {
        int tempNextEl = currentEl;
        list[i] = nextEl;
        list[i+1] = currentEl;
        swaped = 1;
      }
    }
  } while (swaped > 0);

  printf("\nHasil: ");
  for (int i = 0; i <= sizeList - 1; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");

  return 0;
}
