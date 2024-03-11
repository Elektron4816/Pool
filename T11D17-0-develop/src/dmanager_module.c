#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        int tmp;
        int stop;
        do {
            stop = 0;
            for (int i = 0; i < DOORS_COUNT - 1; i++) {
                if (doors[i].id > doors[i + 1].id) {
                    stop = 1;
                    tmp = doors[i].id;
                    doors[i].id = doors[i + 1].id;
                    doors[i + 1].id = tmp;
                }
            }

        } while (stop == 1);
    }
}
void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}