#include "print_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    int h, m, s;
    time_t now;
    struct tm* localtime = (struct tm*)malloc(sizeof(struct tm));
    time(&now);
    localtime = localtime_r(&now, localtime);
    h = localtime->tm_hour;
    m = localtime->tm_min;
    s = localtime->tm_sec;
    printf(Log_prefix " %d:%d:%d ", h, m, s);
    while (*message != '\0') {
        print(*message);
        message++;
    }
}