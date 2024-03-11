#ifndef STATE_H
#define STATE_H
#include <stdio.h>

struct Data {
    int year;
    int mounth;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int cod;
};

struct Data get_by_id(FILE *stream, int id);
void set_by_id(FILE *stream, int id, struct Data *data);

#endif