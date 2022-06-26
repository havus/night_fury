//Deret bilangan Fibonacci
//0 1 1 2 3 5 8 13 ...

#include <stdio.h>

int main()
{
  // int jum,a=0,b=1,c;
  
  // printf("Jumlah bil Fibonacci = "); scanf("%d", &jum);
  
  // for (int i=1; i<=jum; i++) {
  //   if (i == 1) {
  //     printf("%d ", a);
  //   } else if (i == 2) {
  //     printf("%d ", b);
  //   } else {
  //     c = a + b;
  //     a = b;
  //     b = c;

  //     printf("%d ", c);
  //   }
  // }

  // ===========================================================================

  //N = 5
  //Output:
  //5
  //54
  //543
  //5432
  //54321

  int n;
  
  printf("Masukkan n = "); scanf("%d", &n);
  
  for (int baris=n; baris>=1; baris--)
  {
      for (int angka=n; angka>=baris; angka--)
      {
          printf("%d ", angka);
      }
      
      printf("\n");
  }
  
  return 0;
}