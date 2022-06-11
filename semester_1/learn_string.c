#include <stdio.h>
#include <string.h>

int main() {
  printf("Print single quote ' \n");
  printf("Print double quote \" \n");
  printf("Print a backslash\\ within a string \n");
  printf("Using Backspace\b within a string \n");
  printf("Using\tTab within a string \n");

  int lengthChar = sizeof("Hello world");
  printf("Length char is: %d \n", lengthChar);
  printf("Length char is: %lu \n", sizeof("Hello world"));

  // %d	Print an integer number printed in decimal (preceded by a minus sign if the number is negative).
  // %f	Print a floating point number ( in the form dddd.dddddd).
  // %lf got replaced by value of a double variable.
  // %E	Print a floating point number ( in scientific notation: d.dddEddd).
  // %g	Print a floating point number (either as f or E, depending on value and precision).
  // %x	Print an integer number in hexadecimal with lower case letters.
  // %X	Print an integer number printed in hexadecimal with upper case letters.
  // %c	Print a character, got replaced by value of a character variable.
  // %s	Print a string, got replaced by value of a string variable.
  // %o got replaced by a octal value corresponding to integer variable.

  int studentNumber;
  studentNumber = 150;
  printf("Number of students in Class X is %d \n", studentNumber);


  // char name[] = "John";
  // printf("Your name is %s \n", name);

  /*
  A double is a data type in C language that stores high-precision floating-point data or 
  numbers in computer memory. It is called double data type because it can hold the double 
  size of data compared to the float data type. A double has 8 bytes, which is equal
  to 64 bits in size.

  ### Using format specifier options in printf ###
  %[flags][width][.precision]Parameter
  For example, %4c means the entire field (three blanks and one non-blank character) occupies 4 columns, %7.2f means to print a float or double in a field at least 7 spaces wide, with two places to the right of the decimal.
  */

  double price = 1000.123;
  printf("Double value is %f \n", price);
  printf("Double value is %.2f \n", price);
  printf("Double value is %lf \n", price);


  /*
  Avoid using strcat in C code. The cleanest and, most importantly,
  the safest way is to use snprintf:
  */
  char str[80];
  strcpy(str, "These ");
  strcat(str, "strings ");
  strcat(str, "are ");
  strcat(str, "concatenated.");
  printf("%s \n", str);

  // char *firstName    = "John";
  // char *lastName     = "Doe";
  // char fullName[80]  = "Lorem ipsum";
  // strcpy(fullName, "Full name is ");
  // strcat(fullName, firstName);
  // strcat(fullName, " ");
  // strcat(fullName, lastName);
  // printf("%s \n", fullName);

  char fullName[256];
  snprintf(fullName, sizeof(fullName), "%s%s", "John", " Doe");
  printf("His fullname is %s, with size %lu \n", fullName, sizeof(fullName));

  // CONSTANT
  const char *TITLE = "Learn basic c language";
  printf("%s \n", TITLE);


  char inputedName[20];
  printf("Enter your name: \n");
  // scanf("%s", inputedName);
  // scanf("%20[^\n]", inputedName); // handle multi words
  // scanf("%[^\n]", inputedName);
  fgets(inputedName, 20, stdin); // handle multi words
  printf("Your name is %s", inputedName);

  int inputedAge;
  printf("Enter your age: \n");
  scanf("%d", &inputedAge);
  printf("Your name is %d \n", inputedAge);


  // int (*data[2])[5];
  // int x1[5];
  // data[0] = &x1;
  // data[1] = &x1;

  // printf(data[0]);

  return 0;
}
