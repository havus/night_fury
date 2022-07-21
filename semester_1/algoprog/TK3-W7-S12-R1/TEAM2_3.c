#include <stdio.h>
#include <string.h>

struct Address {
  // NamaJalan, NomorRumah, Kota, Provinsi 
  char NamaJalan[100];
  char NomorRumah[100];
  char Kota[100];
  char Provinsi[100];
};

struct Birthday {
  // Tanggal, Bulan dan Tahun
  int Tanggal;
  int Bulan;
  int Tahun;
};

struct Dosen {
  // NoDosen, NIDN, Nama, Alamat, Tempat, TanggalLahir
  char    NoDosen[32];
  char    NIDN[32];
  char    Nama[64];
  char    Tempat[256];
  struct  Address Alamat;
  struct  Birthday TanggalLahir;
};

int main() {
  /*
    3. Buatlah struct sebagai berikut:
    -	Struct Data Dosen berisi NoDosen, NIDN, Nama, Alamat, Tempat, TanggalLahir 
    -	Alamat merupakan struct yang terdiri dari NamaJalan, NomorRumah, Kota, Provinsi 
    -	TanggalLahir merupakan struct yang berisi Tanggal, Bulan dan Tahun 
    Kemudian buatlah program untuk menginput data sebanyak 5 dosen (menggunakan array of structure).
  */

  int jumlahDosen;
  printf("Masukkan jumlah dosen yg diinginkan: "); scanf("%d", &jumlahDosen);

  struct Dosen database[jumlahDosen];

  for (int i = 0; i < jumlahDosen; i++) {
    struct Dosen    tempDosen;
    struct Address  tempAlamat;
    struct Birthday tempBirthday;

    printf("Masukkan NoDosen #%d: ", i+1);      scanf("%s", tempDosen.NoDosen);
    printf("Masukkan NIDN #%d: ", i+1);         scanf("%s", tempDosen.NIDN);
    printf("Masukkan Nama #%d: ", i+1);         scanf("%s", tempDosen.Nama);
    printf("Masukkan Tempat #%d: ", i+1);       scanf("%s", tempDosen.Tempat);

    printf("Masukkan Alamat.NamaJalan #%d: ", i+1);   scanf("%s", tempAlamat.NamaJalan);
    printf("Masukkan Alamat.NomorRumah #%d: ", i+1);  scanf("%s", tempAlamat.NomorRumah);
    printf("Masukkan Alamat.Kota #%d: ", i+1);        scanf("%s", tempAlamat.Kota);
    printf("Masukkan Alamat.Provinsi #%d: ", i+1);    scanf("%s", tempAlamat.Provinsi);

    printf("Masukkan TanggalLahir.Tanggal #%d: ", i+1); scanf("%d", &tempBirthday.Tanggal);
    printf("Masukkan TanggalLahir.Bulan #%d: ", i+1);   scanf("%d", &tempBirthday.Bulan);
    printf("Masukkan TanggalLahir.Tahun #%d: ", i+1);   scanf("%d", &tempBirthday.Tahun);

    tempDosen.Alamat        = tempAlamat;
    tempDosen.TanggalLahir  = tempBirthday;
    database[i]             = tempDosen;
  }

  printf("\nPlease wait we'll print the results...\n\n");

  for (int i = 0; i < jumlahDosen; i++) {
    printf("Dosen #%d:\n", i + 1);
    printf("    NoDosen: %s\n", database[i].NoDosen);
    printf("    NIDN: %s\n",    database[i].NIDN);
    printf("    Nama: %s\n",    database[i].Nama);
    printf("    Tempat: %s\n",  database[i].Tempat);

    printf("    Alamat.NamaJalan: %s\n",  database[i].Alamat.NamaJalan);
    printf("    Alamat.NomorRumah: %s\n", database[i].Alamat.NomorRumah);
    printf("    Alamat.Kota: %s\n",       database[i].Alamat.Kota);
    printf("    Alamat.Provinsi: %s\n",   database[i].Alamat.Provinsi);

    printf("    TanggalLahir.Tanggal: %d\n",  database[i].TanggalLahir.Tanggal);
    printf("    TanggalLahir.Bulan: %d\n",    database[i].TanggalLahir.Bulan);
    printf("    TanggalLahir.Tahun: %d\n",    database[i].TanggalLahir.Tahun);
  }

  return 0;
}
