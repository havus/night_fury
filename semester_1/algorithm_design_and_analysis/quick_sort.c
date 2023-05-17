#include <stdio.h>
#include <stdlib.h>

void quicksort (int* data, int p, int r) {
  if (p>= r) return;

  q = part(p,r, data);
  quicksort(data, p, q-1);
  quicksort(data,q+1, r);
}

int main() {
  int part (int p, int r, int *data) {
    int i = p;
    int j = r;
    int pivot = data[p];

    while (i < j) {
      while (pivot >= data[i]) {
        i++;
      }
      while (pivot > data[j]) {
        j--;
      }
      tukar(data[i], data[j])
    }

    tukar(pivot, data[j])
  }
  return j;
}
