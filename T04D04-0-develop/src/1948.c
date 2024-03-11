#include <math.h>
#include <stdio.h>
int del(int x, int y);
int prostdel(int x);
int pers(int x, int y);

int main() {
    int a, b;
    char z;
    if (scanf_s("%d%c", &a, &z) != 2 || z != '\n') {
        printf("n/a\n");
        return 1;
    } else {
        b = sqrt(a * a);
        printf("%d\n", prostdel(b));
    }
    return 0;
}
int del(int x, int y) {
    int r, z;
    if (x < y) {
        return 0;
    } else {
        z = del(x, y * 2) * 2;
        r = x - z * y;
        return r >= y ? z + 1 : z;
    }
}
int prostdel(int x) {
    int y = 2;
    while (x != 1) {
        if (pers(x, y) == 0) {
            x = del(x, y);
        } else {
            y++;
        }
    }
    return y;
}
int pers(int x, int y) {
    while (x >= y) {
        x = x - y;
    }

    return x;
}