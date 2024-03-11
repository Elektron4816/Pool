#include <stdio.h>
#include <stdlib.h>

void input(int *a, int *n, int *error);
void output(int *a, int *n, int *error);
void sort(int *a, int *n);

int main() {
    int *a;
    int n;
    int error = 0;
    if (scanf("%d", &n) != 1 && n != 0) {
    } else {
        error = 1;
    }

    a = (int *)malloc(n * sizeof(int));
    input(a, &n, &error);

    if (error != 1) {
        sort(a, &n);
    } else {
        error = 1;
    }
    output(a, &n, &error);

    return 0;
}

void input(int *a, int *n, int *error) {
    char c;
    for (int p = 0; p < *n; p++) {
        if (scanf("%d%c", &a[p], &c)) {
            *error = 0;
        } else {
            *error = 1;
            break;
        }
    }
}

void output(int *a, int *n, int *error) {
    if (*error == 0) {
        for (int p = 0; p < *n; p++) {
            printf("%d ", a[p]);
        }
        free(a);
        printf("\n");
    } else {
        printf("n/a");
    }
}
void sort(int *a, int *n) {
    int tmp;
    double stop;
    for (int p = *n - 1; p >= 0; p--) {
        stop = 0;
        for (int i = 0; i < p; i++) {
            if (a[i] > a[i + 1]) {
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                stop = 0;
            }
        }
        if (stop == 1) break;
    }
}