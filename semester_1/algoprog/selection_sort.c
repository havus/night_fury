#include <stdio.h>

int main() {
  int list[5]   = {10, 4, 7, 9, 5};
  int sizeList  = 5;

  int smallestValueIndex;

  for (int i = 0; i <= sizeList - 1; i++) {
    printf(".");
    smallestValueIndex = i;

    // dont have next el, dont need to scan
    if (i == sizeList - 1) {
      continue;
    }

    // nest
    for (int j = i+1; j <= sizeList - 1; j++) {
      printf(".");
      if (list[j] < list[smallestValueIndex]) {
        smallestValueIndex = j;
      }
    }

    if (smallestValueIndex > -1 && smallestValueIndex != i) {
      int tempNextEl = list[i];
      // swap
      list[i]                   = list[smallestValueIndex];
      list[smallestValueIndex]  = tempNextEl;
    }
  }

  printf("\nHasil: ");
  for (int i = 0; i <= sizeList - 1; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");

  return 0;
}
