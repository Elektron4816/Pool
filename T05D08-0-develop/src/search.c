#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n, int *error);
void output(int *a, int *n, int *error);
double mean(int *a, int *n);
double variance(int *a, int *n);

int main() {
    int n, data[NMAX];
    int error = 0;
    error != 1 ? input(data, &n, &error) : printf("n/a");
    output(data, &n, &error);

    return 0;
}
int input(int *a, int *n, int *error) {
    char c;
    // int r;
    if (scanf("%d", n) == 1 && NMAX > *n && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c)) {
            } else {
                *error = 1;
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
            if ((*p % 2 == 0) && (*p >= mean(a, n)) && (*p <= mean(a, n) + 3 * sqrt(variance(a, n))) &&
                (*p != 0)) {
                printf("%d ", *p);
            }
        }
        printf("\b");
    } else if (*error == 1) {
        printf("n/a");
    }
}
double mean(int *a, int *n) {
    double s = 0;
    for (int p = 0; p < *n; p++) {
        s += a[p];
    }
    return s / *n;
}
double variance(int *a, int *n) {
    double s = 0;
    double m = mean(a, n);
    for (int p = 0; p < *n; p++) {
        s += (a[p] - m) * (a[p] - m);
    }
    return s / *n;
}
