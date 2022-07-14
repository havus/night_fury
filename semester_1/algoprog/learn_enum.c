#include <stdio.h>

// c dont know the boolean is
// enum boolean { false, true };
enum boolean { salah, benar };
typedef enum boolean2 { false, true } BOOL;

enum boolean evenNumberCheck(int num) {
  enum boolean result;

  if (num % 2 == 0) {
    // return true;
    return benar;
  }

  // return false;
  return salah;
}

void learnBooelan() {
  int ourNum = 15;
  enum boolean isEvenNumber = evenNumberCheck(ourNum);
  BOOL testBoolean = true;

  printf("testBoolean is %d\n", testBoolean);
  printf("isEvenNumber is %d\n", isEvenNumber);

  if (isEvenNumber) {
    printf("%d is an even number\n", ourNum);
  } else {
    printf("%d is an odd number\n", ourNum);
  }
}

enum days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

void learnEnum() {
  for (int i = Sunday; i <= Saturday; i++) {
    printf("i = %d\n", i);
  }
}

int main() {
  // learnBooelan();
  learnEnum();

  return 0;
}
