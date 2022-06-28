- [Introduction](#introduction)
- [Compilers](#compilers)
- [Hello World](#hello-world)
- [Constants vs Directives](#constants-vs-directives)
- [Quotations](#quotations)
- [Char Type](#char-type)
- [Null Terminator](#null-terminator)
- [Pointers](#pointers)
- [Arrays](#arrays)
- [Enumerators](#enumerators)
- [Memory Allocation with different Types](#memory-allocation-with-different-types)
- [Reallocating Memory](#reallocating-memory)
- [Function Prototypes](#function-prototypes)

## Introduction

This isn't a 'How to program in C' tutorial, this is just a grouping of topics/concepts from the C language that I found interesting while learning the language (from the perspective of an already establed developer). Some of the things I make mention of I have used in other languages but I feel are worth covering still as they might not be immediately obvious to everyone.

When writing a program in a language like [C](https://en.wikipedia.org/wiki/C_(programming_language)), that by itself is not executable (i.e. you can't run a C file). So you need to convert the C source code into [machine code](https://en.wikipedia.org/wiki/Machine_code) (i.e. something the computer's CPU can understand).

Machine code is as low-level as you can get when interacting with a computer. So the C language is considered a 'higher-level' abstraction to save us from having to write machine code ourselves. A language like [Python](https://www.python.org/) is an even 'higher-level' abstraction to save us from having to write C (i.e. the Python language is actually written in C).

In order to convert C code into machine code, we need a compiler.

> Strictly speaking you also need a [linker](https://en.wikipedia.org/wiki/Linker_(computing)) which takes multiple compiled objects and places them into a single executable file. Generally speaking, when we say "compile a C file", we're really combining two separate processes (compiling and linking) into the single generic term "compile"

## Compilers

To compile C source code into an executable you need a compiler, of which there are many options. The two most popular being LLVM's `clang` and GNU's `gcc`.

You might find there is a `cc` available, but typically this is aliased to an existing compiler.

Also, Mac doesn't provide a compiler by default. But if you install X-Code you'll get the LLVM's suite of compilers. Below we see that we get quite a few alias' and all of them point to the same embeded LLVM compiler:

```sh
$ gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.0.0 (clang-800.0.38)
Target: x86_64-apple-darwin15.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
                                                                   
$ llvm-gcc --version
Apple LLVM version 8.0.0 (clang-800.0.38)
Target: x86_64-apple-darwin15.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
                                                                   
$ clang --version
Apple LLVM version 8.0.0 (clang-800.0.38)
Target: x86_64-apple-darwin15.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
                                                                   
$ cc --version
Apple LLVM version 8.0.0 (clang-800.0.38)
Target: x86_64-apple-darwin15.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

The first two alias' `gcc` and `llvm-gcc` are confusing and a bit misleading as their not GNU's version. They're still the LLVM's compiler but in the first instance (`gcc`) the compiler is configured to use some additional libraries that are provided by c++ 

It's worth noting that even with a plain C file all these alias' work to compile the source code into an executable. It's just they allow you to utilise additional extensions not provided by the standard c language.

LLVM's licensing is BSD, meaning Apple can embed it within their own software that is not GPL-licensed. Typically LLVM's compiler is faster, but in some cases might not support all the same targets as GNU's.

> For more comparison details see http://clang.llvm.org/comparison.html

### C11 support

You'll find that some functions provided within C aren't safe. They allow for overflow of data because they don't check that the array defined is able to contain the strings being manipulated.

C11 compatible compilers will provide an additional set of string functions that are safe.

```c
#include <stdio.h>

int main(void)
{
  #if defined __STDC_LIB_EXT1__
    printf("Optional functions are defined.\n");
  #else
    printf("Optional functions are not defined.\n");
  #endif
  
  return 0;
}
```

If your compiler supports these optional (safe) string functions, then to enable them you need to add a `define` directive that modifies the subsequent header file. But you need to add this directive _before_ you include the preprocessor directive that imports the `string.h` header:

```c
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
```

If you don't set `__STDC_WANT_LIB_EXT1__` to `1`, then the header `string.h` will utilise the old (unsafe) string functions.

## Hello World

```c
#include <stdio.h>          // pre-processor directive to include code file at compile time
#define NAME "World"        // pre-processor directive to substitute any reference to NAME _before_ compilation

// returns an int type and takes in no arguments (void)
int main(void) {
  printf("hello %s", NAME); // can't use single quotes
  return 0;                 // zero indicates no problems
}
```

> It's important to note that the directives `#include` and `#define` are 'processed' at the start of the compilation process. This is at the request of the compiler. It'll be one of the compiler's first steps (to pull in the preprocessor and have it ensure the file is setup ready for the reset of the compilation)

You compile it like so:

```sh
cc hello-world.c -o hw
```

Now you have a macOS compatible executable:

```sh
./hw # prints the message "Hello World"
```

> To cross-compile for another OS (e.g. Linux) then use Docker or a VM

## Constants vs Directives

We saw in the above 'Hello World' example the use of the directive `#define` which allowed us to use a single identifier (`NAME` in this case) throughout our program. The benefit is that we can change the value once and have it updated everywhere.

But do not get this confused with a variable. It is not. This is just a sequence of characters that are blindly replaced at the pre-processing stage. The value assigned to `NAME` will be replaced inside your program regardless of whether it's valid code or not. Meaning it could cause the compiler to error in an unclear way.

On the other hand you can define a proper constant like so:

```c
#include <stdio.h>

int main(void) {
  const char NAME[] = "World";
  printf("Hello %s", NAME);
  return 0;
}
```

What this gives you is a variable that has an actual type assigned to it. Meaning the compiler will help you identify an incorrect value if necessary much more easily than using the `#define` directive.

## Quotations

In C single quotes denote a `char` type and double quotes denote a string.

So if you had the following code:

```c
char foo = 'a';
printf("foo: %s\n", foo);
```

It would error with:

```
format specifies type 'char *' but the argument has type 'char'
```

To get it to work you need to provide the memory address location of `foo` using the address-of operator (`&`):

```c
char foo = 'a';
printf("foo: %s\n", &foo);
```

We'll come back to the `&` operator (and understand what `*` means) later, when we discuss [pointers](#pointers).

## Char Type

When creating a variable, and assigning a string to it, the value assigned is really a pointer to a location in memory.

The `char` type is used when storing characters such as `'a'`, but it also allows storing of strings `"abc"`. 

When assigning a string, the pointer is to an _array_ where each element of the array is a character of the provided string. For example the string `"abc"` would be stored in an array that looked something like: 

```c
["a", "b", "c"]
```

This happens even if the string you provide is just one character. Although, depending on your program's design, it could be argued that you should not have assigned a single character string, but instead used single quotes to represent a single `char`. 

When assigning a character (e.g. `a`) to a variable of type `char` it takes on dual duty. Meaning the char type variable can represent the specific character `a` but really it stores the ASCII integer code that defines that character. 

We can also directly assign an integer instead of `a` to the char type variable, and because of these characteristics we can perform arithmetic on the variable:

```c
#include <stdio.h>

int main(void) {
  char foo = 'a';
  printf("foo: %c (%d)\n", foo, foo); // a (97)
  foo = foo + 2;
  printf("foo: %c (%d)\n", foo, foo); // c (99)
  return 0;
}
```

## Null Terminator

Consider the following code:

```c
char my_string[2] = "a";
```

The reason we specify a length of 2 is because the underlying array that `my_string` is being pointed towards looks like this:

```c
["a", "\0"] // yes it has two elements
```

The last element is known as the null terminator. When this data is stored in memory, we can now start at the location in memory where it is stored (its _address_) and then step through memory until we reach the null terminator; where we'll then find the end of the string.

> Note: in some cases you can set your variable to be the actual length of the content (e.g. `char my_string[1] = "a";`) but in some instances this can cause strange overlaps of data and strictly speaking isn't valid code either

## Pointers

When declaring a variable the computer sets aside some memory for the variable. 

Next the variable name is linked to the location in memory that was set aside for it. 

Lastly the value you want to assign to the variable is placed into the relevant location of memory.

Let's consider the following code:

```c
#include <stdio.h>

int main(void) {
  int foo = 1;
  printf("foo: %d\n", foo);

  int *bar;
  int bar_val = 1;
  printf("bar_val: %d\n", bar_val);
  bar = &bar_val;
  printf("bar: %p\n", bar);
  int bar_get_val = *bar;
  printf("bar_get_val: %d\n", bar_get_val);

  return 0;
}
```

So we see that we create a `foo` variable and assign `1` to it. We then print that integer in the typical way.

Next we make a slightly more convoluted version, but this time we utilise a pointer to help us understand what they do.

Here are each of the steps broken down:

- `int *bar;`: we declare a pointer variable called `bar` of type `int` † (we don't initialize it with a value)
- `int bar_val = 1;`: we both declare and initialize the variable `bar_val` as type `int`
- `bar = &bar_val;`: we initialize the pointer variable `bar` to store the memory address location of `bar_val`
- `int bar_get_val = *bar;`: we dereference the address (i.e. follow the pointer) assigned to `bar`

> † meaning we will be assigning an address to this pointer  
> and the content at that memory address location will also be of type `int`

The output of this program is:

```
foo: 1
bar_val: 1
bar: 0x7fff59a1769c
bar_get_val: 1
```

OK, so there are some things that we need to clarify and that's the `*` and `&` operators.

- `*`: value-at-address operator (used when declaring a pointer & when dereferencing a pointer)
- `&`: address-of operator (used to reference the memory address of a variable)

The first thing we should be aware of is that we're not able to print a declared variable that has no value initialized for it. So imagine the following code:

```c
int *bar;
printf("bar: %d\n", bar);
```

This would cause the following compiler error:

```
format specifies type 'int' but the argument has type 'int *'
```

Which makes sense, as we've declared the variable as the type `*bar`. So we can fix that:

```c
int *bar;
printf("bar: %d\n", *bar);
```

> Notice we try to use `*` to dereference the value of `bar`

But this still errors, but now with:

```
variable 'bar' is uninitialized when used here
```

Which again makes sense. Nothing more to say about that portion of the code, I just wanted to make it clear what happens when you try to print an uninitialized variable (and also what happens when that variable is a pointer type).

Continuing through the program, the next line of interest is:

```c
bar = &bar_val;
```

Which gives us the actual location in memory for the variable `bar_val` (i.e. `0x7fff59a1769c`). So the value assigned to `bar` isn't `1`, but the address of `1` in memory.

Finally, we declare and initialize the variable `bar_get_val` with the actual value of `1`, and we do that by using `*` to deference the variable `bar` which contains a memory address:

```c
int bar_get_val = *bar;
```

That is `bar` holds a _memory address_, which isn't a concrete value, it's an indirection to somewhere else. Hence we would say `bar` _points_ to the actual value's location and why we use the 'value-at-address' operator to deference the value.

The following code shows how to print the location in memory of a variable even if it wasn't declared as a pointer, simply by using the address-at operator `&` which itself indicates a pointer to another location:

```c
char foo = 'a';
printf("address of foo: %p\n", &foo);
```

Remember, a memory address isn't the value but a reference to where the value can be found. One analogy I've seen is of your home address on an envelope: the envelope isn't your home, nor is the address written on the envelope. The envelope just indicates where your home can be found.

One last thing to consider/remember is that C doesn't have a String type. It stores strings in an array data structure. An array will automatically return the address location of the first element to the variable it is assigned to. This is why you may have seen a `char` pointer being assigned a variable _without_ the need to use the `&` operator to get the memory address of that variable (because the variable, in this case an array, already provides a memory address).

The following example shows this:

```c
char message[6] = "hello"; // array data structure used and memory location for message[0] returned
char *messagePtr = message; // no need to use &message now
printf("my pointer: %p\n", messagePtr);
printf("my message: %s\n", message);
```

> Note: for comparison of C pointers and Go pointers see https://dave.cheney.net/2014/03/17/pointers-in-go

In C there are two ways to define a pointer: 

1. `char* foo` 
2. `char *foo` 

Both of which are equivalent. 

Although the first seems like the clearer option (as a newbie would read it: "define a variable called `foo` of type 'character pointer'") compared to the second option (which could lead them to think the variable name was `*foo` not `foo`). For me the second option is preferred because otherwise the following code becomes a bit ambiguious:

```c
char* foo, bar;
```

You might (incorrectly) think this would create two variables, both of type 'character pointer', but really only `foo` is the pointer and `bar` is a normal `char` type.

Where as using the second format (`char *foo`), this code becomes much clearer:

```c
char *foo, bar;
```

Lastly, if you want to create a `const` that happens to be a pointer, then the syntax is as follows:

```c
int count = 43;
int *const pcount = &count;
```

We prefix the `const` keyword with the value-at operator `*` and not the variable name.

## Arrays

Consider the following code (which is broken by the way):

```c
#include <stdio.h>

int main(void) {
  char my_string = "abc";
  printf("my_string: %s", my_string);

  return 0;
}
```

This code has the following compiler error:

```
incompatible pointer to integer conversion initializing 'char' with an expression of type 'char [4]'
```

What this error tells us is that the variable `my_string` has a type of `char [4]`, meaning it is actually an array (hence the `[4]` syntax) and so we should have declared the variable like so:

```c
char my_string[4] = "abc";
```

We saw why this is earlier when talking about [null terminators](null-terminator). But just to recap, it's because a string should be stored within an array data structure. So we need to declare it as an array data structure.

We also learned earlier (using this example) why the length of the array is 4 and not 3 (which you may initially have expected which a string of three characters), again to recap: this is because of the extra element added to the array for you "\0" (the null terminator).

So, the reason I'm talking about arrays is because in the original code above (the one before declaring the variable correctly) there were actually two errors linked together. The second part of the error was:

```
format specifies type 'char *' but the argument has type 'char'
```

What this error tells us is that `printf` was expecting a pointer but all it got was something of a `char` type. 

When declaring the variable as an array, we fix both errors.

But both these errors has led some people to incorrectly assume that an array is a pointer, when it is not.

Let's recap why this works. 

When assigning a string, the compiler expects the contents to be stored within an array. Each element within the array is a address to the value given to it in memory. 

So in our example above (i.e. the string `"abc"`), `"a"` is stored in memory and the address of that memory is placed in `my_string[0]`. Next `"b"` is stored in memory and the address of that memory is placed in `my_string[1]` and so on.

A pointer in contrast is a single location in memory, where as an array hold lots of memory addresses.

Because of this, an array variable automatically points to the first element within the array.

This is why if you try to `printf` a string, the compiler will complain if you don't provide a pointer. Because it expects a string to have been stored within an array (which our earlier example didn't). But when storing a string inside an array, the variable that is passed to `printf` would _already_ be a pointer, due to it automatically referencing the first array element as its value.

> Interestingly, an array's type is made up of the element type + the overall array dimension. So `int foo[3]` is a different type to `int bar[4]`. Even though the value type `int` is the same, the array dimension (size/length) is different.

Also, the number of bytes that an array will occupy is the number of elements multiplied by the size of each element.

Lastly, you can define and initialize a string _without_ specifying an array dimension (i.e. no size):

```c
char foobar[] = "No dimension provided!";
```

It leaves it up to the compiler to allocate the required dimension. You can only do this when you initialize the variable with a value. You could use `char foobar[];` as there is no value for the compiler to utilise to know how much memory to allocate.

## Enumerators

Enumerators allow you to define new variable types. They automatically assign numerical values to each of the identifiers within the enumerator (although you do also have control over the specific values as well). This concept is best explained by way of example:

```c
#include <stdio.h>

int main(void) {
  enum weekend {Saturday, Sunday};     // 0, 1
  enum weekend today = Sunday;         // 1
  enum weekend saturday = Saturday;    // 0
  enum weekend yesterday = today - 1;  // 0 now yesterday is Saturday
  printf("today %d\n", today);
  printf("saturday %d\n", saturday);
  printf("yesterday %d\n", yesterday);
  return 0;
}
```

If you wish to provide your own values you can:

```c
enum bool {
  true = 1,
  false = 2
};

enum bool on = true;
enum bool off = false;

printf("on: %d", on);   // 1
printf("off: %d", off); // 2
```

## Memory Allocation with different Types

> See [here](http://www.integralist.co.uk/posts/bits.html) for understanding RAM and bits

### Array

Consider the following code:

```c
int foo[3] = {1,2,3};
printf("foo variable points to = %p\n", foo);

int i = 0;
do {
  printf("foo[%u] = %p\n", i, (void *)(&foo[i]));
  i++;
} while(i < 3);

printf("sizeof(foo) = %lu\n", sizeof(foo));
```

So in this piece of code we create an array and assign it to `foo`. 

Next we print out what the `foo` variable points, which for me outputs:

```
foo variable points to = 0x7fff525fd6ac
```

Then we loop over the `foo` array and print out each element's address, which for me outputs:

```
foo[0] = 0x7fff525fd6ac
foo[1] = 0x7fff525fd6b0
foo[2] = 0x7fff525fd6b4
```

Notice that the `foo` variable and the first element of the `foo` array are the same value: `0x7fff525fd6ac` which is the address of the memory location for the value `1` assigned to `foo[0]`.

> Note: `(void *)(&foo[i])` is interesting in that we're casting the address to `void`. You don't need to do this unless you're passing a variable that is itself a pointer variable to another variable (e.g. `int foo = 1; int *pFoo = foo`) and for that situation you would cast to `void` to prevent a possible warning from the compiler. When using `%p` it will expect the value to be a pointer type, but in cases where you have a pointer variable assigned an `int` variable, then the type of `&pFoo` would actually be a 'pointer to pointer to int'.

Finally we print the size of the `foo` variable, which outputs:

```
sizeof(foo) = 12
```

You might wonder  where the value `12` comes from? Well, this goes back to how data is stored in memory (i.e. a block of memory is 1 byte; so 8 bits). We defined the type of the array to be `int` and (depending on the compiler) that will be either two bytes, four bytes or eight bytes. 

For most 32 bit systems the size of `int` would be four bytes. You can always use `sizeof(int)` to check:

```c
printf("sizeof(int): %ld\n", sizeof(int)); // 4
```

So looking back at our example, we have three array elements, and if each element takes up four bytes then it makes sense the size of the array would be `12` (i.e. `4 + 4 + 4 = 12`).

To calculate the number of items within the array itself, rather than the number of bytes, you can use:

```c
size_t element_count = sizeof foo/sizeof foo[0];
printf("element_count: %zu\n", element_count); // 3
```

> Note: `%z` is for `size_t` and the `u` prevents a `invalid conversion specifier` error.

### Signed vs Unsigned

In C you can define an integer to be either `signed` or `unsigned`. The former means the number can be both negative and positive as well as zero. 

So typically, if a number is negative, you'll prefix it with `-`. If the number is positive, then it is just the number. For example, `-1` and `1`. 

You don't need to explicitly provide the `signed` keyword (e.g. `signed int <var_name>`), it's just implied.

The latter (`unsigned`) is an integer that can only be positive. So if you need to store an integer and you know the value will always be zero or positive, then you can define it as being unsigned and the compiler can make appropriate optimisations based on that understanding.

So although the underlying memory allocation is the same for signed or unsigned, the actual values represented are slightly different in that unsigned allows for storing values that are twice the size of signed, because half of signed's values have to account for negatives.

## Reallocating Memory

With strings you typically define them as follows (i.e. the underlying data structure is an array):

```c
char names[20] = "hello";
```

But this means there is reserved memory that is wasted and if reading from stdin (e.g. user input), then the amount of characters entered could exceed the specified reserved memory allocation.

Below is an example, given as a [Stack Overflow](http://stackoverflow.com/questions/8164000/how-to-dynamically-allocate-memory-space-for-a-string-and-get-that-string-from-u), that reads each character from stdin and reallocates the memory space if required (it's advised that you should ensure reallocation of memory is done as a multiple; such as double the size):

```c
char *getln()
{
    char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Check if we need to stop. */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Check if we need to expand. */
        if (size <= index) {
            size += CHUNK;
            tmp = realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }

        /* Actually store the thing. */
        line[index++] = ch;
    }

    return line;
}
```

There is a very good blog post that covers the steps in detail here: https://brennan.io/2015/01/16/write-a-shell-in-c/. 

They're effectively the same implementation (in principle), except for the use of `getchar` vs `getc` (the former can only read from stdin, where as `getc` can read from any input stream).

```c
#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
```

> Notice `c` variable is declared as an `int` and not a `char`, the author of the blog post makes mention of this as being because `EOF` is an `int` type

The author then goes on to explain that in more recent releases, there is a much shorter version that can be implemented thanks to the `getline` function:

```c
char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}
```

## Function Prototypes

A compiler will error if you try to call a function before it has been defined. This can be mitigated by utilising function prototypes that let you define the signature of the function up front and defer the definition until a later point in time (sort of like defining an interface type):

```c
// Function prototypes
int Foo(double data_values[], size_t count);
int Bar(double *x, size_t n);

int main(void) {
  int f = Foo(...signature...);
  int b = Bar(...signature...)
}

// Definitions for Foo() and Bar()
```