#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * Stack-Implementierung
 *
*/
char push(char c) {
  if (stack.size == (STACKSIZE - 1)) {
    return 0;
  }

  return stack.data[stack.size++] = c;
}

char pop() {
  if (stack.size == 0) {
    return 0;
  }

  return stack.data[--stack.size];
}

char peek() {
  if (stack.size == 0) {
    return 0;
  }

  return stack.data[stack.size-1];
}

