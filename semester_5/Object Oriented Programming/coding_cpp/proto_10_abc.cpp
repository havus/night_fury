/*
  How to run with no error: ./cpp_runner_smt_5.sh proto_10_abc.cpp

  Abstract Base Class (ABC) adalah class yang tidak dapat diinstansiasi dan memiliki "pure virtual functions."
  digunakan sebagai dasar untuk class turunan yg harus mengimplementasikan methods2 base classnya.

  "Pure Virtual Functions"
  ditandai dengan `= 0` pada akhir fungsi.
  class yang memiliki fungsi ini adalah Abstract Base Class.
  digunakan ketika kita ingin memastikan bahwa class turunan wajib menyediakan implementasi fungsi tersebut.

  "Virtual Functions"
  Didefinisikan dengan keyword virtual `tanpa = 0`.
  Memberikan kemampuan polymorphism tanpa menjadikan class sebagai ABC.
  digunakan ketika Anda ingin menyediakan implementasi default yang dapat di-override oleh class turunan. Ini memberikan fleksibilitas untuk mengubah perilaku fungsi di class turunan tanpa memaksa implementasi ulang.

  "Polymorphism" adalah konsep dalam OOP yg memungkinkan func/method untuk beroperasi pada objek dari berbagai class yang merupakan bagian dari hierarki abstract class yang sama. Polymorphism memungkinkan satu antarmuka untuk digunakan dengan berbagai tipe object.
  jenis2:
    Compile-time Polymorphism (Statik):
      Dicapai melalui overloading (fungsi atau operator).
      Contoh: Fungsi dengan nama yang sama tetapi parameter yang berbeda.
    Runtime Polymorphism (Dinamis):
      Dicapai melalui penggunaan fungsi virtual dan pewarisan class.
      Contoh: Overriding metode dalam class turunan.
  fungsi polymorphism:
    - (abstraksi & generalisasi) untuk menggunakan interface umum untuk berbagai tipe objek,
    meningkatkan fleksibilitas dan skalabilitas kode.
    - (extension) untuk lebih mudah penambahan fungsi atau tipe objek baru tanpa mengubah kode yang sdh ada.
    - (sederhana dan terorganisir)
    mengurangi kompleksitas dan pengulangan kode dgn memungkinkan penanganan objek dari class yang berbeda dengan cara yang seragam.


  "Late Binding"
  disebut juga "Dynamic Binding"
  mekanisme keputusan tentang metode mana yg akan dipanggil/dibuat saat runtime, bukan saat kompilasi.
  inti dari runtime polymorphism.
  korelasi:
    - "virtual func": saat method dideklarasikan sebagai virtual di base class,
        C++ menggunakan "late binding" untuk menentukan metode mana yang akan dipanggil
        berdasarkan tipe objek yang sebenarnya, bukan tipe pointer atau reference
    - "vtable (Virtual Table)" C++ mengimplementasikan "late binding" menggunakan tabel virtual (vtable).
        vtable adalah array pointer ke fungsi virtual.
        setiap class yg memiliki virtual func memiliki vtable sendiri, dan setiap objek 
        dari class tersebut memiliki pointer ke vtable tersebut
    - overriding: saat class turunan mengoverride virtual func dari class dasar,
        vtable objek dari class turunan akan menunjuk ke metode yang di-override

  Apakah kita dapat meng-override fungsi-fungsi non-virtual dalam C++? Apa dampaknya jika kita melakukannya?
  - tidak, fungsi non-virtual tidak dapat di-override.
    karena fungsi tidak berpartisipasi dalam mekanisme late binding.
    tapi kita bisa mendefinisikan fungsi dengan nama yang sama di class turunanny.
    ini sering disebut dgn "function hiding".

  --- Contoh function hiding ---
  class Base {
  public:
    void display() const {
      std::cout << "Base display" << std::endl;
    }
  };

  class Derived : public Base {
  public:
    void display() const { // Function hiding
      std::cout << "Derived display" << std::endl;
    }
  };
*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Abstract Base Class
class Player {
public:
  Player(int hp, int arm) : health(hp), armor(arm) {}

  virtual void displayStatus() const {
    std::cout << "Health: " << health << ", Armor: " << armor << std::endl;
  }

  // virtual function: optionally overridden by derived classes
  virtual Player& takeDamage(int damage) {
    int effectiveDamage = damage - armor;
    if (effectiveDamage < 0) effectiveDamage = 0; // damage should not negative value

    health -= effectiveDamage;
    std::cout << "Player took " << effectiveDamage << " damage." << std::endl;
    return *this;
  }

  // "pure virtual function" to be implemented by derived classes
  virtual void displayHeroType() const = 0;

  virtual ~Player() {} // Virtual destructor

protected:
  // shared attribute
  int health;
  int armor;
};

// derived Class 1
class Warrior : public Player {
public:
  Warrior(int hp, int arm) : Player(hp, arm) {}

  void displayHeroType() const override {
    std::cout << "Hero Type: Warrior" << std::endl;
  }
};

// derived Class 2
class Mage : public Player {
public:
  Mage(int hp, int arm) : Player(hp, arm) {}

  void displayHeroType() const override {
    std::cout << "Hero Type: Mage" << std::endl;
  }
};

int main() {
  // using polymorphism to manage different types of players
  // declare a variable with type "vector of unique pointers to Player" not "Warrior or Mage only"
  std::vector<std::unique_ptr<Player>> players;

  players.push_back(std::make_unique<Warrior>(100, 10));
  players.push_back(std::make_unique<Mage>(80, 5));

  for (auto& player : players) {
    player->displayHeroType();
    player->displayStatus();
    player->takeDamage(10).takeDamage(20);
    player->displayStatus();
    std::cout << "\n" << std::endl;
  }

  /*
  Output:
    Hero Type: Warrior
    Health: 100, Armor: 10
    Player took 0 damage.
    Player took 10 damage.
    Health: 90, Armor: 10

    Hero Type: Mage
    Health: 80, Armor: 5
    Player took 5 damage.
    Player took 15 damage.
    Health: 60, Armor: 5
  */

  return 0;
}
