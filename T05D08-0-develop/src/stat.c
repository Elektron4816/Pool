#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *error);
void output(int *a, int *n, int *error);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int error = 0;
    input(data, &n, &error);
    if (error != 1) {
        output(data, &n, &error);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));
    } else {
        error = 1;
        printf("n/a");
    }

    return 0;
}
int input(int *a, int *n, int *error) {
    char c;
    if (scanf("%d", n) == 1 && NMAX > *n && *n > 0) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &c) != 1 || c == '\n') {
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
        printf("\n");
    } else if (*error == 1) {
        printf("1n/a");
    }
}

int min(int *a, int *n) {
    int min;
    for (int p = 0; p < *n; ++p) {
        if (a[p] < min) {
            min = a[p];
        }
    }
    return min;
}
int max(int *a, int *n) {
    int max = 0;
    for (int p = 0; p < *n; p++) {
        if (a[p] > max) {
            max = a[p];
        }
    }
    return max;
}

double mean(int *a, int *n) {
    double s = 0;
    for (int p = 0; p < *n; p++) {
        s += a[p];
    }
    return s / *n;
    ;
}

double variance(int *a, int *n) {
    double s = 0;
    double m = mean(a, n);

    for (int p = 0; p < *n; p++) {
        s += (a[p] - m) * (a[p] - m);
    }
    return s / *n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
