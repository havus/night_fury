/*
  how to run: ./cpp_runner_smt_5.sh TP_2_1.cpp
*/

#include <iostream>
#include <cstdio>

void convertToUSD(float rupiah) {
  const float usdRate = 16477.0;
  float usd = rupiah / usdRate;
  printf("Nilai dalam US Dollar: $%.2f\n", usd);
}

void convertToMYR(float rupiah) {
  const float myrRate = 3491.0;
  float myr = rupiah / myrRate;
  printf("Nilai dalam Ringgit Malaysia: RM%.2f\n", myr);
}

int main() {
  float rupiah;
  char choice;

  printf("Program Konversi Mata Uang\n");
  printf("Masukkan nilai dalam Rupiah: ");
  scanf("%f", &rupiah);
  printf("Pilih konversi:\n");
  printf("a. US Dollar\n");
  printf("b. Ringgit Malaysia\n");
  printf("Pilihan: ");
  scanf(" %c", &choice);

  switch (choice) {
    case 'a':
      convertToUSD(rupiah);
      break;
    case 'b':
      convertToMYR(rupiah);
      break;
    default:
      printf("Pilihan tidak valid\n");
  }

  return 0;
}
