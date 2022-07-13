#include <stdio.h>
#include <string.h>
#include <unistd.h>

// https://en.wikipedia.org/wiki/GNU_coding_standards

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void learnArray() {
  int arr1[] = {1, 2, 3};

  printf("arr1 address is %p\n", arr1); // arr1 is an address of first el
  printf("arr1 address is %p\n", &arr1); // arr1 address is 0x7ff7b40d7e9c
  // address of array will be same as the first element

  for (int i = 0; i < ARRAY_SIZE(arr1); i++) {
    printf("arr1 index %d is %d, address is %p\n", i, arr1[i], &arr1[i]);
    // arr1 index 0 is 1, address is 0x7ff7b40d7e9c
    // arr1 index 1 is 2, address is 0x7ff7b40d7ea0
    // arr1 index 2 is 3, address is 0x7ff7b40d7ea4
  }

  // int arr2[];
  int *ptr_arr;
  ptr_arr = arr1; // same as ptr_arr = &arr1[0];

  printf("array1[0] is %d and value is %p, address is %p\n", *ptr_arr, ptr_arr, &ptr_arr);

  ptr_arr++;
  printf("array1[1] is %d and value is %p, address is %p\n", *ptr_arr, ptr_arr, &ptr_arr);

  // OUTPUT:
  // arr1 address is 0x7ff7bf5d4e9c
  // arr1 address is 0x7ff7bf5d4e9c
  // arr1 index 0 is 1, address is 0x7ff7bf5d4e9c
  // arr1 index 1 is 2, address is 0x7ff7bf5d4ea0
  // arr1 index 2 is 3, address is 0x7ff7bf5d4ea4
  // array1[0] is 1 and value is 0x7ff7bf5d4e9c, address is 0x7ff7bf5d4e90
  // array1[1] is 2 and value is 0x7ff7bf5d4ea0, address is 0x7ff7bf5d4e90
}

void learnArrayChar() {
  // char str[] = {};
  char str[] = {'A', 'B'};
  char str2[] = "Hello"; // same as {'H', 'e', 'l', 'l', 'o', '\0'}
  char str3[] = "Hello"; // same as {'H', 'e', 'l', 'l', 'o', '\0'}

  printf("str size is %lu and str[0] is %c \n", ARRAY_SIZE(str), str[0]);
  printf("str2 size is %lu and str2[0] is %c \n", ARRAY_SIZE(str2), str2[0]);

  // printf("str2 and str3 is same? %s \n", str2 == str3 ? "yes" : "no"); // warning: array comparison always evaluates to false
  printf("str2 and str3 is same? %d \n", strcmp(str2, str3)); // same will return 0, NOT same will return -49

  // OUTPUT:
  // 1 warning generated.
  // str size is 2 and str[0] is A 
  // str2 size is 6 and str2[0] is H 
  // str2 and str3 is same? no 
  // str2 and str3 is same? 0
}

void learnPrintAnimation() {
  char sentence[] = "Hello world";
  int sleepDuration = 100; // in millisecond;

  for (int i = 0; i < strlen(sentence); i++) {
    printf("%c", sentence[i]);

    usleep(sleepDuration * 1000); // * 1000 cz microsecond;
    fflush(stdout);
    // 1 second = 1.000.000 microsecond
    // 1 second = 1.000 millisecond
  }

  printf("%s", "\n");
}

int main() {
  // learnArray();
  // learnArrayChar();
  learnPrintAnimation();

  return 0;
}
