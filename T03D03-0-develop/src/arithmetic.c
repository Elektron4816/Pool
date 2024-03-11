#include <stdio.h>

int main() {
  int x, y;
  char z;
  if (scanf("%d%d%c", &x, &y, &z) != 3 || z != '\n') {
    printf("n/a\n");
    return 1;
  }
  if (x && y) {
    printf("%d %d %d %d\n", x + y, x - y, x * y, x / y);
  } else {
    printf("%d %d %d n/a\n", x + y, x - y, x * y);
  }

  return 0;
}