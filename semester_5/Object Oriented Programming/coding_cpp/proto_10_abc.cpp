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
  Memberikan kemampuan polymorphism tanpa menjadikan kelas sebagai ABC.
  digunakan ketika Anda ingin menyediakan implementasi default yang dapat di-override oleh kelas turunan. Ini memberikan fleksibilitas untuk mengubah perilaku fungsi di kelas turunan tanpa memaksa implementasi ulang.
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
