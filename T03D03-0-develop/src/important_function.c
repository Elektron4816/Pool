#include <math.h>
#include <stdio.h>
int main() {
  double x;
  char c;
  double y;
  if (scanf("%lg%c", &x, &c) != 2 || c != '\n') {
    printf("n/a\n");
  } else {
    y = 7e-3 * pow(x, 4) +
        ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) -
        x * pow(10 + x, 2 / x) - 1.01;
    printf("%g\n", y);
  }
  return 0;
}