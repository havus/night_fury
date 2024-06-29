/*
  How to run with no error: ./cpp_runner_smt_5.sh proto_9_array.cpp

  array biasa:
  - dideklarasikan dengan ukuran tetap yg diketahui.
  - alokasi memori dilakukan di stack (untuk array lokal) atau di heap (untuk array dinamis).

  std::array:
  - dideklarasikan dengan ukuran tetap yg diketahui.
  - alokasi memori dilakukan di stack.
  - ukuran array dapat diketahui dengan size() atau max_size().
  - lebih aman karena memiliki fungsi-fungsi yang memastikan tidak terjadi buffer overflow.
  - additional member function seperti size(), at(), begin(), end(), dll.

  std::vector:
  salah satu kontainer dalam C++ Standard Library yg menyediakan array dinamis (dapat berubah ukuran).
  bagian dari header <vector>. dan memungkinkan elemen-elemen ditambahkan atau dihapus,
  dan akan mengelola memori secara otomatis.

  Iterator: objek yang digunakan untuk iterasi melalui elemen-elemen dalam kontainer (seperti std::vector). bekerja seperti pointer, yg menunjuk ke elemen dalam kontainer. mendukung operasi seperti pengaksesan nilai yg ditunjuk, increment, dan perbandingan.

  Alasan mengapa iterator digunakan pada std::vector
    "Abstraksi": Memisahkan algoritma dari detail implementasi kontainer. memungkinkan penggunaan umum fungsi-fungsi seperti std::sort, std::find, dll.
    "Fleksibilitas": digunakan dengan berbagai algoritma standar dalam <algorithm>.
    "Keamanan": memungkinkan akses yg aman ke elemen-elemen dalam kontainer, lebih aman dibandingkan dengan penggunaan pointer biasa.

  - dideklarasikan dengan ukuran dinamis.
  - alokasi memori dilakukan di heap. dan akan menangani alokasi dan dealokasi memori secara "otomatis".
  - ukuran array dapat diketahui dengan size() atau max_size().
  - lebih fleksibel karena ukuran array dapat berubah.
  - dapat diubah secara dinamis menggunakan metode seperti push_back(), resize(), dan insert()
  - additional member function mirip seperti std::array.


  Performa dalam Pengolahan Data Besar:

  Array
    Kecepatan Akses: sangat cepat krn memori dialokasikan secara berkelanjutan dan tidak ada overhead member function.
    Alokasi Memori: sangat cepat, tetapi ukuran stack terbatas sehingga tidak cocok untuk data besar.
    Overhead Rendah: Tidak ada overhead tambahan, tidak seperti std::vector atau std::array.

  std::array
    Kecepatan Akses: Mirip dengan array biasa karena memori dialokasikan secara berkelanjutan di stack.
    Overhead Tambahan: Sedikit overhead karena method dan member function, tapi masih ringan dan efisien.
    Ukuran Tetap: Tidak dapat diubah setelah deklarasi, jadi kurang fleksibel untuk pengolahan data besar yg memerlukan ukuran dinamis.

  std::vector
    Kecepatan Akses: Akses sedikit lebih lambat dibandingkan array dan std::array karena manajemen dinamis, tetapi masih sangat cepat.
    Alokasi Memori: Memori dialokasikan di heap dan dapat ditingkatkan sesuai kebutuhan. Ini membuat std::vector sangat fleksibel untuk pengolahan data besar.
    Overhead Tambahan: Overhead untuk manajemen ukuran dinamis, termasuk reallocation mem saat kapasitas penuh. Re-allocation mem ini mahal jika sering terjadi.
    Fragmentasi Memori: Bisa menyebabkan fragmentasi memori karena alokasi dinamis di heap, dan dapat mempengaruhi performa dalam pengolahan data besar.


  Kesimpulan
    Array cocok ketika ukuran data tetap dan yg membutuhkan performa tinggi dengan overhead minimal. ga cocok untuk data besar yg memerlukan ukuran dinamis.
    std::array mudah digunakan dan ada fitur tambahan dibandingkan array biasa, performa tetap tinggi karena alokasi memori di stack. tapi, tidak fleksibel untuk data yg ukurannya berubah-ubah.
    std::vector adalah pilihan terbaik untuk pengolahan data besar yang memerlukan ukuran dinamis dan manajemen memori otomatis, meskipun dengan sedikit kekurangan dalam hal overhead dan potensi fragmentasi memori.
*/

#include <iostream>
#include <array> // for size() and max_size()
#include <vector>
#include <cstdio>

using namespace std;

template <size_t N>
void printArray(int (&arr)[N]) {
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

template <size_t N>
void printArray(const std::array<int, N>& arr) {
  for (size_t i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void array1() {
  int arr[3];

  arr[0] = 100;
  arr[1] = 200;
  arr[2] = 300;
  printArray(arr);
}

void array2() {
  array<int, 5> arr = {1, 2, 3, 4, 5};

  // additional features:
  printf("arr size: %zu\n", arr.size());
  arr.at(0) = 1;

  printArray(arr);
}

void vector1() {
  vector<int> numbers;

  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);

  cout << "\nlooping with for" << endl;
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << "Element at index " << i << ": " << numbers[i] << endl;
  }

  cout << "\nlooping with iterator" << endl;

  vector<int>::iterator it;
  for (it = numbers.begin(); it != numbers.end(); it++) {
    int index = distance(numbers.begin(), it);
    cout << "Element at index " << index << ": " << *it << endl;
    // cout << *it << " ";
  }

  // reverse iterator
  cout << "\nlooping with reverse iterator" << endl;

  std::vector<int>::reverse_iterator rit;
  for (rit = numbers.rbegin(); rit != numbers.rend(); rit++) {
    int index = distance(numbers.rbegin(), rit);
    cout << "Element at index " << index << ": " << *rit << endl;
  }
  cout << endl;
}

int main() {
  array1();
  array2();
  vector1();
}
