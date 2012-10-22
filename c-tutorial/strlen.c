#include <stdio.h>

/*
 * einfache implementierung von strlen(..)
 *
*/
int _strlen(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }

  return p - s;
}

int main() {
  char s[100];

  scanf("%s", s);

  printf("Laenge: %d\n", _strlen(s));
}
