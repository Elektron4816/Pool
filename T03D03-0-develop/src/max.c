#include <stdio.h>
int max(int x, int y);

int main() {
  int x, y;
  char z;
  if (scanf("%d%d%c", &x, &y, &z) != 3 || z != '\n') {
    printf("n/a\n");
    return 1;
  } else {
    printf("%d\n", max(x, y));
  }
}
int max(int x, int y) {
  if (x > y)
    return x;
  if (x <= y)
    return y;

  return 0;
}