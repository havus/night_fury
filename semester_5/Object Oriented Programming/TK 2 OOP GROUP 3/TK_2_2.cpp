#include <iostream>
#include <cstdio>
using namespace std;

double calculateSalary(int golongan, int lemburan) {
  double gajiPokok, pajak, lemburRupiah = 0.0, gajiTotal;
  int totalLemburanUnder3 = lemburan > 3 ? 3 : lemburan;

  switch (golongan) {
    case 1:
      gajiPokok = 5000000;
      pajak = 0.05;
      break;
    case 2:
      gajiPokok = 4000000;
      pajak = 0.04;
      break;
    case 3:
      gajiPokok = 3000000;
      pajak = 0.03;

      if (totalLemburanUnder3 > 0) {
        lemburRupiah = totalLemburanUnder3 * 100000;
      }
      lemburRupiah += (lemburan - totalLemburanUnder3) * 50000;
      break;
    case 4:
      gajiPokok = 2000000;
      pajak = 0.02;

      if (totalLemburanUnder3 > 0) {
        lemburRupiah = totalLemburanUnder3 * 150000;
      }
      lemburRupiah += (lemburan - totalLemburanUnder3) * 50000;
      break;
    default:
      printf("Golongan tidak valid\n");
      return 0.0;
  }

  gajiTotal = gajiPokok + lemburRupiah;
  gajiTotal -= (gajiTotal * pajak);

  return gajiTotal;
}

int main() {
  int golongan, lemburan;

  // example 1
  golongan = 1;
  lemburan = 3; // in hours
  printf("Golongan: %d\n", golongan);
  printf("Lemburan: %d Jam\n", lemburan);
  printf("Gaji: %.2f\n\n", calculateSalary(golongan, lemburan));

  // example 2
  golongan = 3;
  lemburan = 4; // in hours
  printf("Golongan: %d\n", golongan);
  printf("Lemburan: %d Jam\n", lemburan);
  printf("Gaji: %.2f\n", calculateSalary(golongan, lemburan));

  return 0;
}
