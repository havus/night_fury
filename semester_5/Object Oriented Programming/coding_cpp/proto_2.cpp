#include <iostream>
#include <string>

using namespace std;

template <typename T>
T getMax(T a, T b) {
  return (a > b) ? a : b;
}

int main() {
  int a = 10, b = 20;
  double x = 25.5, y = 17.5;
  
  printf("Max of %d and %d is %d\n", a, b, getMax(a, b));
  printf("Max of %f and %f is %f\n", x, y, getMax(x, y));

  return 0;
}
