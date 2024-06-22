/*
  How to run with no error: ./cpp_runner_smt_5.sh proto_8_control_statement.cpp
*/

#include <iostream>
using namespace std;

void ifExample() {
  int x = 10;
  if (x > 5) {
    cout << "x is greater than 5" << endl;
  }
}
void ifElseExample() {
  int x = 3;
  if (x > 5) {
    cout << "x is greater than 5" << endl;
  } else {
    cout << "x is not greater than 5" << endl;
  }
}
void multipleIfElseExample() {
  int x = 7;
  if (x > 10) {
    cout << "x is greater than 10" << endl;
  } else if (x > 5) {
    cout << "x is greater than 5 but less than or equal to 10" << endl;
  } else {
    cout << "x is 5 or less" << endl;
  }
}

void switchExample() {
  int day = 4;
  switch (day) {
    case 1:
      cout << "Monday" << endl;
        break;
    case 2:
      cout << "Tuesday" << endl;
        break;
    case 3:
      cout << "Wednesday" << endl;
        break;
    case 4:
      cout << "Thursday" << endl;
        break;
    case 5:
      cout << "Friday" << endl;
        break;
    default:
      cout << "Weekend" << endl;
  }
}

void nestedIfExample() {
  int x = 10;
  int y = 20;

  if (x > 5) {
    if (y > 15) {
      cout << "x is greater than 5 and y is greater than 15" << endl;
    }
  }
}

void danglingElseExample() {
  // warning: add explicit braces to avoid dangling else [-Wdangling-else]
  int x = 5;
  int y = 10;

  if (x > 0)
    if (y > 5)
      cout << "y is greater than 5" << endl;
    else
      cout << "x is not greater than 0" << endl;
}

void danglingElseExampleFixed() {
  int x = 5;
  int y = 10;

  if (x > 0) {
    if (y > 5)
      cout << "y is greater than 5" << endl;
    else
      cout << "x is not greater than 0" << endl;
  }
}

int main() {
  ifExample();
  ifElseExample();
  multipleIfElseExample();
  switchExample();
  nestedIfExample();
  danglingElseExample();
  danglingElseExampleFixed();

  return 0;
}
