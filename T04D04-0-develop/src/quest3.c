#include <stdio.h>

int Fib(int x);

int main() {
    int n;
    char d;
    if (scanf("%d%c", &n, &d) != 2 || d != '\n') {
        printf("n/a\n");
        return 1;
    } else if (n < 0) {
        printf("n/a\n");
        return 1;
    } else {
        int F = Fib(n);
        printf("%d\n", F);
    }
    return 0;
}

int Fib(int x) {
    int a = 1, b = 1;
    int k = 3;
    while (k <= x) {
        b = a + b;
        a = b - a;
        k++;
    }
    return b;
}