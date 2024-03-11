#include <stdio.h>
#include <stdlib.h>

#include "state.h"

void read(char *filename);
void sort(char *filename);
int up(struct Data *data1, struct Data *data2);
void set_by_id(FILE *stream, int id, struct Data *data);
struct Data get_by_id(FILE *stream, int id);
long int size(char *filename);
void add(char *filename);

int main() {
    char filename[50];
    int a;
    scanf("%50s", filename);
    scanf("%d", &a);
    switch (a) {
        case 0:
            read(filename);
            break;
        case 1:
            sort(filename);
            read(filename);
            break;
        case 2:
            add(filename);
            sort(filename);
            read(filename);
            break;
        default:
            printf("n/a");
            break;
    }
    return 0;
}
void read(char *filename) {
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long int size = ftell(f) / sizeof(struct Data);
    fclose(f);
    FILE *fp = fopen(filename, "rb");
    for (int i = 0; i < 3; i++) {
        struct Data data = get_by_id(fp, i);
        printf("%d %d %d %d %d %d %d %d\n", data.year, data.mounth, data.day, data.hour, data.minute,
               data.second, data.status, data.cod);
    }
    printf("...\n");
    for (int i = size - 2; i < size; i++) {
        struct Data data = get_by_id(fp, i);
        printf("%d %d %d %d %d %d %d %d\n", data.year, data.mounth, data.day, data.hour, data.minute,
               data.second, data.status, data.cod);
    }
    fclose(fp);
}

void sort(char *filename) {
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long int size = ftell(f) / sizeof(struct Data);
    fclose(f);
    FILE *fp = fopen(filename, "r+b");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            struct Data data1 = get_by_id(fp, j);
            struct Data data2 = get_by_id(fp, j + 1);
            if (up(&data1, &data2)) {
                set_by_id(fp, j + 1, &data1);
                set_by_id(fp, j, &data2);
            }
        }
    }
    fclose(fp);
}

int up(struct Data *data1, struct Data *data2) {
    int res = 0;
    if (data1->year > data2->year) {
        res = 1;
    }
    if (data1->year == data2->year) {
        if (data1->mounth > data2->mounth) {
            res = 1;
        }
        if (data1->mounth == data2->mounth) {
            if (data1->day > data2->day) {
                res = 1;
            }
            if (data1->day == data2->day) {
                if (data1->hour > data2->hour) {
                    res = 1;
                }
            }
        }
    }
    return res;
}

void add(char *filename) {
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long int size = ftell(f) / sizeof(struct Data);
    FILE *fp = fopen(filename, "r+b");
    struct Data data;
    if (scanf("%d %d %d %d %d %d %d %d", &data.year, &data.mounth, &data.day, &data.hour, &data.minute,
              &data.second, &data.status, &data.cod) == 8) {
        set_by_id(fp, size, &data);
        fclose(fp);
    } else {
        printf("n/a");
    }
}