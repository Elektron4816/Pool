#include <stdio.h>

int main() {
  double x, y;
  char z;
  if (scanf("%lf%lf%c", &x, &y, &z) != 3 || z != '\n') {
    printf("n/a\n");
    return 1;
  }
  if ((x * x) + (y * y) < 25) {
    printf("GOTCHA\n");
  } else {
    printf("MISS\n");
  }
  return 0;
}