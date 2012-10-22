#include <stdio.h>

int call_by_value(int x[]) {
  *++x;
}

int main() {
  int x[] = { 1, 2};

  call_by_value(x);

  printf("%d\n", x[0]);
}
