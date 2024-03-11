#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "log_levels.h"

FILE* log_init(char* filename) {
    FILE* log_file = fopen(filename, "a+");
    return log_file;
}
int logcat(FILE* log_file, char* pub, char* message, enum log_level level) {
    switch (level) {
        case 0:
            fprintf(log_file, "DEBUG   ");
            break;
        case 1:
            fprintf(log_file, "TRACE   ");
            break;
        case 2:
            fprintf(log_file, "INFO    ");
            break;
        case 3:
            fprintf(log_file, "WARNING ");
            break;
        case 4:
            fprintf(log_file, "ERROR   ");
            break;
    }
    long int s_time;
    struct tm* m_time;
    char str_t[128] = "";
    s_time = time(NULL);
    m_time = localtime(&s_time);
    strftime(str_t, 128, "%x %A %X", m_time);
    fprintf(log_file, "%s \"%s\" %s", str_t, pub, message);
    return 0;
}
int log_close(FILE* log_file) {
    fclose(log_file);
    return 0;
}
