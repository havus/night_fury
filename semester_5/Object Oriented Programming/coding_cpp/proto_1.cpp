#include <iostream>
#include <math.h>
#include <signal.h>
#include <time.h>
#include <string>

using namespace std;

/*
  %c untuk menampilkan karakter
  %s untuk menampilkan teks (string)
  %d, %i untuk menampilkan bilangan desimal
  %f untuk menampilkan bilangan pecahan
  %o untuk menampilkan bilangan oktal
  %x untuk menampilkan bilangan heksadesimal
  \t untuk membuat tabs
*/

void hello() {
  std::cout << "Hello, World!" << std::endl;
  cout << "Yuhu" << endl;

  // auto name = string("Variable Name Auto");
  // std::cout << name << std::endl;

  printf("Hello all!\n");
  printf("Age: %d\n", 12);
}

void inputName1() {
  string name;
  cin >> name;
  cout << "Hi " << name;
}
void inputName2() {
  char name[50];
  printf("Enter your name: ");
  scanf("%s", name);
  printf("My Name is %s\n", name);
}
void inputAge1() {
  int age;
  cout << "Enter your age: ";
  scanf("%d", &age);
  printf("Age = %d\n", age);
}

void tryPointer() {
  int a = 10;
  int *p;
  p = &a;
  cout << "Address of a: " << &a << endl;
  cout << "Value of a: " << a << endl;
  cout << "Address of p: " << p << endl;
  cout << "Value of p: " << *p << endl;
}
void calculator1() {
  unsigned int total_belanja;

  cout << "Masukan total belanja: ";
  cin >> total_belanja;

  if (total_belanja > 5000) {
    cout << "Selamat! anda dapat hadiah" << endl;
  } else if (total_belanja > 4000) {
    cout << "Anda dapat hadiah ketika menambah belanja " << 5000 - total_belanja << endl;
  } else {
    cout << "Anda belum dapat hadiah" << endl;
  }
}
void looping1() {
  int i = 0;
  while (i < 3) {
    cout << i << endl;
    i++;
  }

  for (i = 0; i < 3; i++){
    printf("Loop-%i\n", i);
  }
}
void array1() {
  int arr[5] = {1, 2, 3, 4, 5};

  arr[2] = 10;

  for (int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
  }

  // sizeof(nilai) / sizeof(*nilai)
  cout << "Length of array: " << sizeof(arr) / sizeof(*arr) << "\n---- DEBUG ----" << sizeof(arr) << "\n---" << sizeof(*arr) << endl;

  array<string, 5> names = {"Ali", "Abi", "Ami", "Mia", "Nia"};
  printf("Name size: %lu\n", names.size());
}
void say_hello(string name) {
  cout << "Hello " << name << "!\n";
}
int custom_sum(int num_1, int num_2) {
  return num_1 + num_2;
}
enum Level { EASY = 1, NORMAL = 2, HARD = 3 };
enum Hari { SENIN, SELASA, RABU, KAMIS, JUMAT, SABTU, MINGGU };

void testLevel(Level gameLevel) {
  // enum OrderStatus = { PENDING, CANCELLED = -1, PAID, SHIPPING, DELIVERED };
  // const int PENDING   = 1;
  // const int CANCELED  = -1;
  // const int PAID      = 2;
  // const int SHIPPING  = 3;
  // const int DELIVERED = 4;

  // Level gameLevel = Level(NORMAL);

  if (gameLevel == HARD) {
    printf("Anda sudah mancapai level maksimal %u\n", gameLevel);
  } else {
    printf("Anda sudah mancapai level %u, teruskan!\n", gameLevel);
  }
}

struct Player {
  string hero_name;
  int health;
  enum Role { TANK, MARKSMAN, MAGE };
  Role role;
  // enum Role { TANK, MARKSMAN, MAGE } role; // this is also fine
};

Player buildPlayer() {
  Player new_player = {"Tigreal", 500, Player::TANK};
  return new_player;
}
string humanizeRole(Player::Role role) {
  return (
    role == Player::TANK ? "Tank" :
      role == Player::MARKSMAN ? "Marksman" :
        "Mage");
}

struct Book {
  string name;
};
struct Mahasiswa {
  string name;
  string address;
  int age;
  Book favoriteBook;
};

Mahasiswa buildMahasiswa() {
  Book new_book = { "The Power of 3" };
  Mahasiswa new_mhs = { "Budi", "Jakarta", 22, new_book };
  return new_mhs;
}

int main() {
  // hello();
  // inputName1();
  // inputName2();
  // inputAge1();
  // tryPointer();
  // calculator1();
  // looping1();
  // array1();
  // say_hello("Budi");
  // printf("Return value is %d\n", custom_sum(1, 2));
  // testLevel(EASY);
  // buildPlayer();
  // printf("Role is %s\n", humanizeRole(Player::TANK).c_str());
  // Player player = buildPlayer();
  // printf("Hero name: %s, role is %s\n", player.hero_name.c_str(), humanizeRole(player.role).c_str());
  Mahasiswa new_mhs = buildMahasiswa();
  printf("Fav book: \"%s\"\n", new_mhs.favoriteBook.name.c_str());

  return 0;
}
