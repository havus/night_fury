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
      // use operator overloading here
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
};

int main() {
  CarRentalSystem system;

  // Program harus dapat membaca dan menulis informasi mobil ke dalam file teks (mobil.txt). Data mobil akan disimpan dalam format teks yang mudah dibaca dan dapat dimodifikasi. (insert dan update data mobil)
  system.loadCarsFromFile("mobil.txt");

  system.addCar(new Sedan("Porche Taychan", 2020, 100, true));
  system.addCar(new Sedan("Tesla Model S", 2020, 100, true));
  system.addCar(new SUV("Toyota Fortuner", 2004, 150, true));
  system.addCar(new SUV("Toyota Rush", 2004, 150, true));
  system.addCar(new SUV("Mitsubishi Pajero Sport", 2004, 150, true));
  system.addCar(new Minivan("Honda Odyssey", 2021, 200, true));

  system.saveCarsToFile("mobil.txt");

  cout << "------ Rent Car Section -------" << endl;
  system.rentCar("Nama pelanggan #1", "Toyota Fortuner", 3);

  cout << "\n------ Print transaction Section -------" << endl;
  system.printTransactions();

  // 4.	Program harus dapat melakukan pencarian dengan nama mobil dan sorting daftar mobil berdasarkan:
  //  a.	Nama secara ascending
  //  b.	Tahun keluaran secara descending

  cout << "\n------ Print searchCarByName -------" << endl;
  system.searchCarByName("Porche Taychan");

  cout << "\n------ sortCarsByName AND Print -------" << endl;
  system.sortCarsByName();
  system.printCars();

  cout << "\n------ sortCarsByYear AND Print -------" << endl;
  system.sortCarsByYear();
  system.printCars();

  return 0;
}
