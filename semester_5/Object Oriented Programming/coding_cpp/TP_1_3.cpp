/*
  how to run: ./cpp_runner_smt_5.sh TP_1_3.cpp
*/

#include <iostream>
#include <string>
#include <cstdio> // Include the <cstdio> header for printf

using namespace std;

string getName() {
  string name;
  printf("Enter your name: ");
  getline(cin, name);
  return name;
}

int getAge() {
  int age;
  printf("Enter your age: ");
  cin >> age;
  return age;
}

double getAmount(int age) {
  double amount = 0;

  if (age >= 0 && age <= 1) {
    printf("is a Baby.\n");
    amount = 1000000;
  } else if (age > 1 && age <= 3) {
    printf("is a Toddler (Batita).\n");
    amount = 1000000;
  } else if (age > 3 && age <= 5) {
    printf("is a Preschooler (Balita).\n");
    amount = 1000000;
  } else if (age > 5 && age <= 12) {
    printf("is a Child.\n");
    amount = 1000000;
  } else if (age > 12 && age <= 17) {
    printf("is a Teenager.\n");
    amount = 1500000;
  } else if (age > 17 && age <= 30) {
    printf("is a Young Adult.\n");
    amount = 1500000;
  } else if (age > 30 && age <= 60) {
    printf("is an Adult.\n");
    amount = 1500000;
  } else if (age > 60) {
    printf("is a Senior.\n");
    amount = 2000000;
  } else {
    printf("Invalid age input.\n");
    return -1; // Error code for invalid age
  }

  return amount;
}

int main() {
  string name = getName();
  int age = getAge();

  if (age < 0) {
    printf("Invalid age input.\n");
    return 1;
  }

  double amount = getAmount(age);
  if (amount == -1) {
    return 1; // Exit program if invalid age
  }

  printf("%s will receive Rp %.0f in assistance.\n", name.c_str(), amount);

  return 0;
}
