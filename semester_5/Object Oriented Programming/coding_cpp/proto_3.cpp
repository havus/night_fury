#include <iostream>
using namespace std;

class MyClass {
public:
  static int count;
  /*
  `static int count;` <-- Static Data Member:
  dalah variabel MyClass yang berbagi nilai di antara semua objek dari kelas tersebut.
  semua objek dari class tersebut memiliki akses ke variabel yang sama.
  dan jika satu objek mengubah nilai dari static data member, perubahan tersebut akan terlihat oleh semua objek lainnya.
  */

  MyClass() {
    // constructor
  }

  static void addCount() {
    /*
    Static Member Function
    adalah fungsi anggota class yang dapat dipanggil tanpa memerlukan objek dari kelas tersebut (public).
    Fungsi ini hanya dapat mengakses static data member dan static member function lain dari class.
    */
    count++;
  }

  static void showCount() {
    cout << "Count: " << count << endl;
  }
};

int MyClass::count = 0; // put this outside from `main` function -- error: definition or redeclaration of 'count' not allowed inside a function

int main() {
  MyClass::addCount(); // static member function to add count variable
  MyClass::addCount();
  MyClass::addCount();
  MyClass::addCount();
  MyClass::showCount();
  printf("Count: %d\n", MyClass::count);

  return 0;
}