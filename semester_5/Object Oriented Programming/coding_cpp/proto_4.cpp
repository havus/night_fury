/*
Functions:
  blok code yang dapat dipanggil untuk menjalankan tugas tertentu.
  dapat memiliki parameter dan mengembalikan nilai.

Constructor:
  fungsi khusus dalam kelas yang secara otomatis dipanggil ketika objek dari kelas (instance) tersebut dibuat.
  digunakan untuk menginisialisasi objek.

Destructor:
  fungsi khusus dalam kelas yang secara otomatis dipanggil ketika objek dari kelas tersebut dihancurkan.
  digunakan untuk membersihkan dan mengelola sumber daya yang dialokasikan oleh objek.

function parameter "Pass by Value":
  Mengirim salinan dari nilai parameter ke fungsi.
  Perubahan yang dilakukan dalam fungsi tidak mempengaruhi nilai asli.

function parameter "Pass by Reference":
  Mengirim referensi (alias) dari parameter ke fungsi.
  Perubahan yang dilakukan dalam fungsi "akan mempengaruhi nilai asli".

function parameter "Pass by Pointer":
  Mengirim alamat dari parameter ke fungsi.
  Perubahan yang dilakukan melalui pointer "akan mempengaruhi nilai asli".
*/

#include <iostream>
#include <string>

using namespace std;

class Player {
public:
  string name;
  int health;

  Player(string playerName, int playerHealth) {
    name = playerName;
    health = playerHealth;
    cout << "Player " << name << " created with health " << health << endl;
  }

  ~Player() {
    cout << "Player " << name << " destroyed" << endl;
  }

  // this is an instance method
  void displayStatus() {
    cout << "Player: " << name << ", Health: " << health << endl;
  }

  // pass by value
  void takeDamageByValue(int damage) {
    damage += 5;
    health -= damage;
  }

  // pass by reference
  void takeDamageByRef(int& damage) {
    damage += 5; // NOTE: modifying the parameter affects the original variable
    health -= damage;
  }

  // pass by pointer
  void takeDamageByPointer(int* damage) {
    *damage += 5; // NOTE: modifying the value at the pointer
    health -= *damage;
  }
};


int main() {
  Player john("John Doe", 100); // <-- constructor called here

  int damage = 5;

  john.takeDamageByValue(damage);
  printf("#takeDamageByValue Damage: %d.", damage);
  john.displayStatus();

  john.takeDamageByRef(damage);
  printf("#takeDamageByRef Damage: %d.", damage);
  john.displayStatus();

  john.takeDamageByPointer(&damage);
  printf("#takeDamageByPointer Damage: %d.", damage);
  john.displayStatus();

  return 0; // <-- destructor called here
}
