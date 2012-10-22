#include <stdio.h>

int b;

void sub(int a) {
  b = b - 1;
}

int main() {
  int a = 10;
  sub(a);

  return 0;
}
