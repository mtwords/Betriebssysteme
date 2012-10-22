#include <stdio.h>
#include "stack.h"

int main() {
  char s[10];
  // Eingabe einlesen
  scanf("%s", s);

  int i;
  for(i = 0; i < sizeof(s); i++) {
    if (s[i] == '(') {
    } else if (s[i] == ')') {
      pop();
    }
  }
  if (stack.size != 0) {
    printf("Fail\n");
  } else {
    printf("Success\n");
  }
}
