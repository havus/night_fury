/*
  How to run with no error: ./cpp_runner_smt_5.sh 5_dangling_pointer.cpp
  How to run with error: ./cpp_runner_smt_5_sanitize_address.sh 5_dangling_pointer.cpp

  we are un lucky cause this is not error without address sanitizer, "undefined behavior" is not error

  OUTPUT:

  [Before] Location: 0x104f006f0 - Value: 7
  =================================================================
  ==85883==ERROR: AddressSanitizer: heap-use-after-free on address 0x000104f006f0 at pc 0x00010226b9b4 bp 0x00016db96a20 sp 0x00016db96a18
  READ of size 4 at 0x000104f006f0 thread T0
      #0 0x10226b9b0 in example1() 5_dangling_pointer.cpp:79
      #1 0x10226bbd8 in main 5_dangling_pointer.cpp:92
      #2 0x185c190dc  (<unknown module>)

  0x000104f006f0 is located 0 bytes inside of 4-byte region [0x000104f006f0,0x000104f006f4)
  freed by thread T0 here:
      #0 0x102b1ace0 in wrap_free+0x98 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x52ce0)
      #1 0x10226b950 in example1() 5_dangling_pointer.cpp:76
      #2 0x10226bbd8 in main 5_dangling_pointer.cpp:92
      #3 0x185c190dc  (<unknown module>)

  previously allocated by thread T0 here:
      #0 0x102b1aba4 in wrap_malloc+0x94 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x52ba4)
      #1 0x10226b850 in example1() 5_dangling_pointer.cpp:72
      #2 0x10226bbd8 in main 5_dangling_pointer.cpp:92
      #3 0x185c190dc  (<unknown module>)

  SUMMARY: AddressSanitizer: heap-use-after-free 5_dangling_pointer.cpp:79 in example1()
  Shadow bytes around the buggy address:
    0x000104f00400: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00480: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00500: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00580: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00600: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  =>0x000104f00680: fa fa fa fa fa fa fa fa fa fa fa fa fa fa[fd]fa
    0x000104f00700: fa fa 00 00 fa fa 00 04 fa fa 00 06 fa fa 00 06
    0x000104f00780: fa fa fd fd fa fa fd fd fa fa fa fa fa fa fa fa
    0x000104f00800: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00880: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x000104f00900: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  Shadow byte legend (one shadow byte represents 8 application bytes):
    Addressable:           00
    Partially addressable: 01 02 03 04 05 06 07 
    Heap left redzone:       fa
    Freed heap region:       fd
    Stack left redzone:      f1
    Stack mid redzone:       f2
    Stack right redzone:     f3
    Stack after return:      f5
    Stack use after scope:   f8
    Global redzone:          f9
    Global init order:       f6
    Poisoned by user:        f7
    Container overflow:      fc
    Array cookie:            ac
    Intra object redzone:    bb
    ASan internal:           fe
    Left alloca redzone:     ca
    Right alloca redzone:    cb
  ==85883==ABORTING
  ./cpp_runner_smt_5_sanitize_address.sh: line 2: 85883 Abort trap: 6           ./simple
*/

#include <iostream>
#include <string>

using namespace std;

void example1() {
  int* danglingPointer = (int*)malloc(sizeof(int));
  *danglingPointer = 7;
  printf("[Before] Location: %p - Value: %d\n", danglingPointer, *danglingPointer);

  free(danglingPointer);

  // Undefined behavior: https://en.wikipedia.org/wiki/Undefined_behavior
  printf("Location: %p - Value: %d\n", danglingPointer, *danglingPointer);
}

void example2() {
  int* danglingPointer = new int(10);
  printf("[Before] Location: %p - Value: %d\n", danglingPointer, *danglingPointer);

  delete danglingPointer;

  printf("Location: %p - Value: %d\n", danglingPointer, *danglingPointer);
}

int main() {
  example1();
  example2();

  return 0;
}
