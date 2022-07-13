#include <stdio.h>
#include <string.h>

struct Birth { // structure data type
  int day, month, year;
};

struct Person { // structure data type
  char    firstName[32];
  char    lastName[32];
  int     age;
  struct  Birth birthday;
};
// } andi, budi; // global variable of struct

struct Person people[3]; // array of struct max 3 person;

typedef struct Student {
  char  name[32];
  int   age;
} Stdnt; // Stdnt is an alias name of struct Student


// bit field example
struct {
  unsigned short icon       : 8;
  unsigned short color      : 4;
  unsigned short underline  : 1;
  unsigned short blink      : 1;
} screen[25][80]; // total 14 bit = 2 bytes



int main() {
  struct Person andi;
  andi.age = 7;
  // *andi.firstName = "andi";
  strcpy(andi.firstName, "andi");

  struct Birth andiBirthday = { 1, 1, 2000 };
  andi.birthday = andiBirthday;

  printf("andi.firstName = %s\n", andi.firstName);
  printf("andi.age = %d\n", andi.age);
  printf("andi.birthday = %d/%d/%d\n", andi.birthday.day, andi.birthday.month, andi.birthday.year);

  struct Person budi = { "budi", "\0", 11 };
  printf("budi.firstName = %s\n", budi.firstName);
  printf("budi.lastName = %s\n", budi.lastName);
  printf("budi.age = %d\n", budi.age);

  Stdnt john = { "John doe", 15 };
  printf("john.name = %s\n", john.name);

  return 0;
}
