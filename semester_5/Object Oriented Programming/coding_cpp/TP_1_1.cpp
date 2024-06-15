/*
  how to run: ./cpp_runner_smt_5.sh TP_1_1.cpp
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void exampleStreamInput() {
  int number;
  cout << "Enter a number: ";
  cin >> number;
  cout << "You entered: " << number << endl;
}

void exampleStreamOutput() {
  cout << "Hello, World!" << endl;
}

void exampleStreamManipulator() {
  int num = 77;
  cout << "Number with setw: " << setw(5) << num << endl;
}

void exampleStreamErrorState() {
  ifstream file("example.txt");
  if (!file) {
    cout << "Error opening file" << endl;
  } else {
    cout << "File opened successfully" << endl;
  }
}

int main() {
  exampleStreamInput();
  exampleStreamOutput();
  exampleStreamManipulator();
  exampleStreamErrorState();

  return 0;
}