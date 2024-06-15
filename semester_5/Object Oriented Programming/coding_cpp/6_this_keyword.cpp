/*
  how to run: ./cpp_runner_smt_5.sh 6_this_keyword.cpp

  keyword `this` adalah pointer ke objek yang member functionnya dipanggil.
  memungkinkan akses ke instance dan metode dalam member function.
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

  // this is an instance method
  void displayStatus() {
    cout << "Player: " << name << ", Health: " << health << endl;
  }

  Player& takeDamage(int damage) {
    health -= damage;
    return *this; // Returning the object itself to enable method chaining
  }
};


int main() {
  Player john("John Doe", 100); // <-- constructor called here

  int damage = 5;

  john.takeDamage(5);
  john.displayStatus();

  john.takeDamage(5).takeDamage(5).takeDamage(5).takeDamage(5).displayStatus();

  return 0; // <-- destructor called here
}
