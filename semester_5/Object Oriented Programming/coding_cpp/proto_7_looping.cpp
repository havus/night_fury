/*
  How to run with no error: ./cpp_runner_smt_5.sh proto_7_looping.cpp
*/

#include <iostream>
using namespace std;

void forLoopExample() {
  for (int i = 0; i < 5; i++) {
    cout << "This is `for` iteration number: " << i << endl;
  }
}
void whileLoopExample() {
  int i = 0;
  while (i < 5) {
    cout << "This is `while` iteration number: " << i << endl;
    i++;
  }
}
void doWhileLoopExample() {
  int i = 0;
  do {
    cout << "This is `do while` iteration number: " << i << endl;
    i++;
  } while (i < 5);
}

void breakLoopExample() {
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      break;
    }
    cout << "i: " << i << endl;
  }
}

void continueLoopExample() {
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      continue;
    }
    cout << "i: " << i << endl;
  }
}

int main() {
  forLoopExample();
  whileLoopExample();
  doWhileLoopExample();

  cout << "Break example" << endl;
  breakLoopExample();

  cout << "Continue example" << endl;
  continueLoopExample();
  return 0;
}
