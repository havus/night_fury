/*
  how to run: ./cpp_runner_smt_5.sh TP_2_2.cpp

  please use c++ 11 or later to compile this code
    warning: 'override' keyword is a C++11 extension [-Wc++11-extensions]
*/

#include <iostream>
#include <cstdio>

// BASE CLASS
class Vehicle {
public:
  virtual void tampilkanInformasi() = 0; // Pure virtual function
};

class Car : public Vehicle {
public:
  void tampilkanInformasi() override {
    printf("Informasi Kendaraan\n");
    printf("Nama   = Mobil\n");
    printf("Jumlah Roda    = 4 Buah\n\n");
  }
};

class Motocycle : public Vehicle {
public:
  void tampilkanInformasi() override {
    printf("Informasi Kendaraan\n");
    printf("Nama   = Motor\n");
    printf("Jumlah Roda    = 2 Buah\n\n");
  }
};

class Bajaj : public Vehicle {
public:
  void tampilkanInformasi() override {
    printf("Informasi Kendaraan\n");
    printf("Nama   = Bajaj\n");
    printf("Jumlah Roda    = 3 Buah\n\n");
  }
};

int main() {
  printf("C++ version: %ld\n\n", __cplusplus);

  Car mobil;
  Motocycle motor;
  Bajaj bajaj;

  mobil.tampilkanInformasi();
  motor.tampilkanInformasi();
  bajaj.tampilkanInformasi();

  return 0;
}
