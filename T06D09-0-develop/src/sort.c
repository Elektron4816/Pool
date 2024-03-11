#include <stdio.h>

#define NMAX 10

void input(int *a, int *error);
void output(int *a, int *error);
void sort(int *a);

int main() {
    int data[NMAX];
    int error = 0;
    input(data, &error);
    error != 1 ? sort(data) : printf("n/a");
    output(data, &error);

    return 0;
}

void input(int *a, int *error) {
    char c;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d%c", p, &c) != 1 || c == '\n') {
            *error = 0;
        } else {
            *error = 2;
            break;
        }
    }
}

void output(int *a, int *error) {
    if (*error == 0) {
        for (int *p = a; p - a < NMAX; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a");
    }
}
void sort(int *a) {
    int i;
    int tmp;
    int stop;
    do {
        stop = 0;
        for (i = 0; i <= NMAX - 1; i++) {
            if (a[i] > a[i + 1]) {
                stop = 1;
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }

    } while (stop == 1);
}
