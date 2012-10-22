#include <stdlib.h>

// definition
struct point {
  int x;
  long y;
} point; // <-- kuerzeste Schreibweise (ohne typedef verwendbar)

int main() {
  struct point my_point;

  // mittels typedef
  // typedef truct point t_point;

  my_point.x = 5;
  my_point.y = 10;
}
