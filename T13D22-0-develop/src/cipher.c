#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

void read(char *filename);
void write(char *filename);

int main(void) {
    char filename[50];
    int a;
    int err = 1;
    while (err) {
        scanf("%d", &a);
        switch (a) {
            case -1:
                err = 0;
                break;
            case 1:
                read(filename);
                break;
            case 2:
                write(filename);
                break;
            default:
                printf("n/a");
                err = 0;
                break;
        }
    }
    return 0;
}

void read(char *filename) {
    scanf("%50s", filename);
    FILE *fp = fopen(filename, "r");
    FILE *log_file = log_init("log.txt");
    if (fp) {
        char c;
        logcat(log_file, filename, "file is open\n", 2);
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        printf("\n");
        logcat(log_file, filename, "file read\n", 2);
        fclose(fp);
        logcat(log_file, filename, "file is closed\n", 2);

    } else {
        printf("n/a\n");
        logcat(log_file, filename, "file not found\n", 4);
    }

    log_close(log_file);
}

void write(char *filename) {
    FILE *fp = fopen(filename, "r+");
    FILE *log_file = log_init("log.txt");
    char c[256];
    getchar();
    fgets(c, 256, stdin);
    if (fp) {
        logcat(log_file, filename, "file is open\n", 2);
        fprintf(fp, "%s", c);
        rewind(fp);
        while (fgets(c, 256, fp)) {
            printf("%s", c);
        }
        logcat(log_file, filename, "file edit\n", 0);
        fclose(fp);
        logcat(log_file, filename, "file is closed\n", 2);
    } else {
        printf("n/a\n");
    }
}