#include <stdio.h>

int main()
{
  // char kal[50];
  // int p, l, Luas;

  // printf("Masukkan panjang dan lebar = "); scanf("%d %d", &p, &l);
  // //printf("Masukkan lebar = "); scanf("%d", &l);

  // //Luas = p*l;
  // printf("Luas = %d\n", p*l);

  // ===========================================================================

  int a=10,b=10,c;

  printf("Nilai a awal = %d\n", a);
  c = a++; //Isi c dengan a, lalu tambahkan a dengan 1
  printf("Nilai a akhir= %d\n", a);
  printf("Nilai c = %d\n", c);

  printf("Nilai b awal = %d\n", b);
  c = ++b; //Tambahkan b dengan 1, lalu isi ke c
  printf("Nilai b akhir = %d\n", b);
  printf("Nilai c = %d\n", c);

  return 0;
}