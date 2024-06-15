/*
  how to run: ./cpp_runner_smt_5.sh TP_1_2.cpp
*/

#include <iostream>
#include <string>

using namespace std;

namespace Game {
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
}

int main() {
  Game::Player player1("John", 100);
  player1.displayStatus();
  player1.takeDamage(20).displayStatus();
  return 0;
}
