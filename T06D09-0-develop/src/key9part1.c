#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length, int *error);
void output(int *number, int *numbers, int *tmp, int *error);
void sum_numbers(int *buffer, int *length, int *number);
int find_numbers(int *buffer, int *length, int *number, int *numbers, int *tmp);

int main() {
    int buffer[NMAX];
    int length, number, numbers[NMAX];
    number = 0;
    int tmp = 0;
    int error = 0;
    input(buffer, &length, &error);
    if (error != 1) {
        sum_numbers(buffer, &length, &number);
        find_numbers(buffer, &length, &number, numbers, &tmp);
        output(&number, numbers, &tmp, &error);
    } else {
        error = 1;
        printf("n/a");
    }
    return 0;
}

void sum_numbers(int *buffer, int *length, int *number) {
    for (int i = 0; i < *length; i++) {
        if (buffer[i] % 2 == 0) {
            *number += buffer[i];
        }
    }
}

int find_numbers(int *buffer, int *length, int *number, int *numbers, int *tmp) {
    for (int *p = buffer; p - buffer < *length; p++) {
        if (*p != 0) {
            if (*number % *p == 0) {
                numbers[*tmp] = *p;
                *tmp += 1;
            }
        }
    }
    return 1;
}

void input(int *buffer, int *length, int *error) {
    char c;
    if (scanf("%d%c", length, &c) == 2 && NMAX >= *length && *length > 0 && c != ' ') {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d%c", p, &c) == 2 || c == '\n') {
                continue;
            } else {
                *error = 1;
                break;
            }
        }
    } else {
        *error = 1;
    }
}

void output(int *number, int *numbers, int *tmp, int *error) {
    if (*error == 0) {
        if (*number != 0) {
            printf("%d\n", *number);
            for (int *p = numbers; p - numbers < *tmp; p++) {
                printf("%d ", *p);
            }

        } else {
            printf("n/a");
        }
        printf("\b\n");
    } else if (*error == 1) {
        printf("n/a");
    }
}
