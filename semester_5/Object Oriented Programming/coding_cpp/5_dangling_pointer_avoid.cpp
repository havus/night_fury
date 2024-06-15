/*
  How to run: ./cpp_runner_smt_5.sh 5_dangling_pointer_avoid.cpp
  How to run: ./cpp_runner_smt_5_sanitize_address.sh 5_dangling_pointer_avoid.cpp


  OUTPUT:

  [Before] Location: 0x1036006f0 - Value: 7
  [Before] Location: 0x1036006d0 - Value: 10
*/

#include <iostream>
#include <string>

using namespace std;

void example1() {
  int* danglingPointer = (int*)malloc(sizeof(int));
  *danglingPointer = 7;
  printf("[Before] Location: %p - Value: %d\n", danglingPointer, *danglingPointer);

  free(danglingPointer);
  danglingPointer = nullptr; // prevent dangling pointer by setting to nullptr

  // Undefined behavior: https://en.wikipedia.org/wiki/Undefined_behavior
  // printf("Location: %p - Value: %d\n", danglingPointer, *danglingPointer); // <- lucky, this will be error now
}

void example2() {
  int* danglingPointer = new int(10);
  printf("[Before] Location: %p - Value: %d\n", danglingPointer, *danglingPointer);

  delete danglingPointer;
  danglingPointer = nullptr; // prevent dangling pointer by setting to nullptr

  // printf("Location: %p - Value: %d\n", danglingPointer, *danglingPointer); // <- lucky, this will be error now
}

int main() {
  example1();
  example2();

  return 0;
}
