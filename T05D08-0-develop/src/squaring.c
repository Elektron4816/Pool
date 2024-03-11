#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *error);
void output(int *a, int *n, int *error);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    int error = 0;
    input(data, &n, &error);
    error != 2 ? squaring(data, &n) : printf("n/a");
    output(data, &n, &error);

    return 0;
}

int input(int *a, int *n, int *error) {
    char c;
    if (scanf("%d", n) == 1 && NMAX > *n && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c) == 2 || c == '\n' || c == ' ') {
                continue;
            } else {
                *error = 2;
                break;
            }
        }
    } else {
        *error = 1;
    }
    return 0;
}

void output(int *a, int *n, int *error) {
    if (*error == 0) {
        for (int *p = a; p - a < *n; p++) {
            printf("%d ", *p);
        }
        printf("\b");
    } else if (*error == 1) {
        printf("n/a");
    }
}

void squaring(int *a, int *n) {
    for (int p = 0; p < *n; p++) {
        a[p] = pow(a[p], 2);
    }
}
