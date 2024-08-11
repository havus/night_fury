/*
  how to run: ./cpp_runner_smt_5.sh ujian.cpp
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Base class for cars
class Car {
protected:
  string name;
  int year;
  double rentalPricePerDay;
  bool available;

public:
  Car(string n, int y, double price, bool avail)
    : name(n), year(y), rentalPricePerDay(price), available(avail) {}

  virtual ~Car() {}

  string getName() const { return name; }
  int getYear() const { return year; }
  double getRentalPricePerDay() const { return rentalPricePerDay; }
  bool isAvailable() const { return available; }

  void setAvailable(bool avail) { available = avail; }
  void setName(const string& n) { name = n; }
  void setYear(int y) { year = y; }
  void setRentalPricePerDay(double price) { rentalPricePerDay = price; }

  virtual double calculateRentalCost(int days) const = 0;

  // output operator overloading
  friend ostream& operator<<(ostream& os, const Car& car) {
    os << car.name << "," << car.year << "," << car.rentalPricePerDay << "," << (car.available ? "available" : "not available");
    return os;
  }

  // input operator overloading
  friend istream& operator>>(istream& is, Car& car) {
    string avail;
    is >> car.name >> car.year >> car.rentalPricePerDay >> avail;
    car.available = (avail == "available");
    return is;
  }
};

class Sedan : public Car {
public:
  Sedan(string n, int y, double price, bool avail)
    : Car(n, y, price, avail) {}

  double calculateRentalCost(int days) const override {
    return rentalPricePerDay * days;
  }
};

class SUV : public Car {
public:
  SUV(string n, int y, double price, bool avail)
    : Car(n, y, price, avail) {}

  double calculateRentalCost(int days) const override {
    return rentalPricePerDay * days * 1.1; // 10% additional charge
  }
};

class Minivan : public Car {
public:
  Minivan(string n, int y, double price, bool avail)
    : Car(n, y, price, avail) {}

  double calculateRentalCost(int days) const override {
    return rentalPricePerDay * days * 1.2; // 20% additional charge
  }
};

class RentalTransaction {
  string customerName;
  Car* rentedCar;
  int rentalDays;
  double totalCost;

public:
  RentalTransaction(string customer, Car* car, int days)
    : customerName(customer), rentedCar(car), rentalDays(days) {
    totalCost = rentedCar->calculateRentalCost(rentalDays);
    rentedCar->setAvailable(false);
  }

  void printTransaction() const {
    cout << "Customer: " << customerName << ", Car: " << rentedCar->getName()
        << ", Days: " << rentalDays << ", Total Cost: " << totalCost << endl;
  }
};

// Main Class for system here!
// sebuah kelas untuk mengelola transaksi sewa mobil
class CarRentalSystem {
  vector<Car*> cars;
  vector<RentalTransaction> transactions;

public:
  ~CarRentalSystem() {
    for (Car* car : cars) {
      delete car;
    }
  }

  void addCar(Car* car) {
    cars.push_back(car);
  }

  void rentCar(string customerName, string carName, int days) {
    for (Car* car : cars) {
      if (car->getName() == carName && car->isAvailable()) {
        transactions.push_back(RentalTransaction(customerName, car, days));
        cout << "Car rented successfully!" << endl;
        return;
      }
    }
    cout << "Car not available!" << endl;
  }

  void printTransactions() const {
    for (const RentalTransaction& rt : transactions) {
      rt.printTransaction();
    }
  }

  void saveCarsToFile(const string& filename) const {
    ofstream file(filename);
    for (const Car* car : cars) {
      // cout << "DEBUG:" << *car << endl;
      file << *car << endl;
    }
  }

  void loadCarsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
      cout << "Could not open file " << filename << endl;
      return;
    }

    string name;
    int year;
    double price;
    string avail;

    while (file >> name >> year >> price >> avail) {
      bool available = (avail == "available");

      // https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
      if (name.find("Sedan") != string::npos) {
        cars.push_back(new Sedan(name, year, price, available));
      } else if (name.find("SUV") != string::npos) {
        cars.push_back(new SUV(name, year, price, available));
      } else if (name.find("Minivan") != string::npos) {
        cars.push_back(new Minivan(name, year, price, available));
      }
    }
  }

  void searchCarByName(const string& name) const {
    for (const Car* car : cars) {
      // cout << "DEBUG:" << car->getName() << name << endl;
      if (car->getName() == name) {
        cout << *car << endl;
        return;
      }
    }
    cout << "Car not found!" << endl;
  }

  void sortCarsByName() {
    sort(cars.begin(), cars.end(), [](Car* a, Car* b) {
      return a->getName() < b->getName();
    });
  }

  void sortCarsByYear() {
    sort(cars.begin(), cars.end(), [](Car* a, Car* b) {
      return a->getYear() > b->getYear();
    });
  }

  void printCars() const {
    for (const Car* car : cars) {
      cout << *car << endl;
    }
  }

  void updateCarData(const string& name) {
    for (Car* car : cars) {
      if (car->getName() == name) {
        string newName;
        int newYear;
        double newPrice;
        bool newAvail;
        string availInput;

        cout << "Enter new name: ";
        getline(cin, newName);
        cout << "Enter new year: ";
        cin >> newYear;
        cin.ignore();
        cout << "Enter new rental price per day: ";
        cin >> newPrice;
        cin.ignore();
        cout << "Is the car available? (yes/no): ";
        getline(cin, availInput);
        newAvail = (availInput == "yes") || (availInput == "y");

        car->setName(newName);
        car->setYear(newYear);
        car->setRentalPricePerDay(newPrice);
        car->setAvailable(newAvail);

        cout << "Car data updated successfully!" << endl;
        return;
      }
    }
    cout << "Car not found!" << endl;
  }

  void menu() {
    int choice;

    do {
      cout << "\nCar Rental System Menu\n";
      cout << "1. Add Car\n";
      cout << "2. Rent Car\n";
      cout << "3. View Transactions\n";
      cout << "4. Insert/Update Car Data\n";
      cout << "5. View Cars (Sorted)\n";
      cout << "6. Search Car by Name\n";
      cout << "7. Save Cars to File\n";
      cout << "8. Load Cars from File\n";
      cout << "9. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      cin.ignore();

      if (cin.fail()) {
          cin.clear(); // Clear the fail state
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input in the buffer
          cout << "Invalid input. Please enter a number.\n";
      } else {
        switch (choice) {
        case 1: {
          string name;
          int year;
          double price;
          bool avail;
          int type;

          string availInput;

          cout << "Enter car type (1 for Sedan, 2 for SUV, 3 for Minivan): ";
          cin >> type;
          cin.ignore();
          cout << "Enter car name: ";
          getline(cin, name);
          cout << "Enter car year: ";
          cin >> year;
          cin.ignore();
          cout << "Enter rental price per day: ";
          cin >> price;
          cin.ignore();
          cout << "Is the car available? (yes/no): ";
          getline(cin, availInput);
          avail = (availInput == "yes") || (availInput == "y");

          if (type == 1) {
            addCar(new Sedan(name, year, price, avail));
          } else if (type == 2) {
            addCar(new SUV(name, year, price, avail));
          } else if (type == 3) {
            addCar(new Minivan(name, year, price, avail));
          }

          cout << "Car added successfully!" << endl;
          break;
        }
        case 2: {
          string customerName, carName;
          int days;

          cout << "Enter customer name: ";
          getline(cin, customerName);
          cout << "Enter car name: ";
          getline(cin, carName);
          cout << "Enter rental duration (days): ";
          cin >> days;
          cin.ignore();

          rentCar(customerName, carName, days);
          break;
        }
        case 3:
          printTransactions();
          break;
        case 4: {
          string name;
          cout << "Enter car name to update: ";
          getline(cin, name);
          updateCarData(name);
          break;
        }
        case 5: {
          int sortChoice;
          cout << "Sort by: 1. Name (Ascending), 2. Year (Descending): ";
          cin >> sortChoice;
          cin.ignore();

          if (sortChoice == 1) {
            sortCarsByName();
          } else if (sortChoice == 2) {
            sortCarsByYear();
          }
          printCars();
          break;
        }
        case 6: {
          string name;
          cout << "Enter car name to search: ";
          getline(cin, name);
          searchCarByName(name);
          break;
        }
        case 7:
          saveCarsToFile("mobil.txt");
          cout << "Cars saved to file successfully!" << endl;
          break;
        case 8:
          loadCarsFromFile("mobil.txt");
          cout << "Cars loaded from file successfully!" << endl;
          break;
        case 9:
          cout << "Exiting program..." << endl;
          break;
        default:
          cout << "Invalid choice! Please try again." << endl;
        }
      }
    } while (choice != 9);
  }
};

int main() {
  CarRentalSystem system;
  system.menu();

  // system.addCar(new Sedan("Porche Taychan", 2020, 100, true));
  // system.addCar(new Sedan("Tesla Model S", 2020, 100, true));
  // system.addCar(new SUV("Toyota Fortuner", 2004, 150, true));
  // system.addCar(new SUV("Toyota Rush", 2004, 150, true));
  // system.addCar(new SUV("Mitsubishi Pajero Sport", 2004, 150, true));
  // system.addCar(new Minivan("Honda Odyssey", 2021, 200, true));
  return 0;
}
