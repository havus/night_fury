#include <stdio.h>
#include <string.h>

#define basicSalary             2000000
#define minimumWorkHoursInMonth 176
#define overtimeRate            3000


int calculatePositionalAllowance(int jobLevel) {
  double allowancePercentage = 0;

  switch (jobLevel) {
    case 1:
      allowancePercentage = 0.05;
      break;
    case 2:
      allowancePercentage = 0.1;
      break;
    case 3:
      allowancePercentage = 0.15;
      break;
    // default:
      // do nothing;
  }

  return basicSalary * allowancePercentage;
}

double defineAllowancePercentageFromEducation(char golPendidikan[]) {
  if (!strcmp("SMA", golPendidikan) || !strcmp("sma", golPendidikan)) {
    return 0.025;
  }

  if (!strcmp("D3", golPendidikan) || !strcmp("d3", golPendidikan)) {
    return 0.05;
  }

  if (!strcmp("S1", golPendidikan) || !strcmp("s1", golPendidikan)) {
    return 0.1;
  }

  return 0;
}

int main() {
  char employeeName[256], lastEducation[3];
  int jobLevel, totalWorkHoursInMonth;

  // input process
  printf("Silahkan isi nama karyawan: ");
  scanf("%s", employeeName);

  printf("Silahkan isi golongan jabatan: ");
  scanf("%d", &jobLevel);

  printf("Silahkan isi golongan pendidikan: ");
  scanf("%s", lastEducation);

  printf("Silahkan isi jumlah jam kerja: ");
  scanf("%d", &totalWorkHoursInMonth);

  // 1 day = 8 jam
  // 1 month = 176 hours

  int totalPositionalAllowance  = calculatePositionalAllowance(jobLevel);
  int totolEducationAllowance   = basicSalary * defineAllowancePercentageFromEducation(lastEducation);
  int totalOvertimeAllowance    = (totalWorkHoursInMonth - minimumWorkHoursInMonth) * overtimeRate;

  // avoid negative value from totalOvertimeAllowance
  if (totalOvertimeAllowance < 0) {
    totalOvertimeAllowance = 0;
  }

  int totalSalary = basicSalary + totalPositionalAllowance + totolEducationAllowance + totalOvertimeAllowance;

  printf("Nama Karyawan %s\n", employeeName);
  printf("Tunjangan Jabatan Rp: %d\n", totalPositionalAllowance);
  printf("Tunjangan Pendidikan Rp: %d\n", totolEducationAllowance);
  printf("Honor Lembur Rp: %d\n", totalOvertimeAllowance);
  printf("Total Gaji Rp: %d\n", totalSalary);

  // TEST CASE 1:
  // Input:
  // Silahkan isi nama karyawan: John
  // Silahkan isi golongan jabatan: 2
  // Silahkan isi golongan pendidikan: S1
  // Silahkan isi jumlah jam kerja: 192
  // Output:
  // Nama Karyawan John
  // Tunjangan Jabatan Rp 200000 (2.000.000 * 10%)
  // Tunjangan Pendidikan Rp 200000 (2.000.000 * 10%)
  // Honor Lembur Rp 2442000
  // Total Gaji Rp 4842000 (2000000 + 200000 + 200000 + 2442000)

  // TEST CASE 2:
  // Input:
  // Silahkan isi nama karyawan: John
  // Silahkan isi golongan jabatan: 1
  // Silahkan isi golongan pendidikan: sma
  // Silahkan isi jumlah jam kerja: 150
  // Output:
  // Nama Karyawan John
  // Tunjangan Jabatan Rp 100000
  // Tunjangan Pendidikan Rp 50000 (2000000 * 0,025)
  // Honor Lembur Rp 2442000
  // Total Gaji Rp 2150000 (2.000.000 + 100.000 + 50.000 + 0)

  return 0;
}