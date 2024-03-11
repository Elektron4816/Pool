#include "s21_string.h"

#include <stdio.h>

int s21_strlen(char *string) {
    int length = 0;
    for (; *(string + length); length++)
        ;
    return length;
}

int s21_strcmp(char *string1, char *string2) {
    int s1 = s21_strlen(string1);
    int s2 = s21_strlen(string2);

    if (s1 > s2)
        return 1;
    else if (s1 < s2)
        return -1;

    while (*string1 == *string2 && *string1) {
        string1++, string2++;
    }

    if ((*string1 - *string2) < 0) {
        return -1;
    } else if ((*string1 - *string2)) {
        return 1;
    }
    return 0;
}

char *s21_strcpy(char *destination, char *source) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    return destination;
}

char *s21_strcat(char *destination, char *append) {
    int i = 0;
    int p = s21_strlen(destination);
    while (append[i] != '\0') {
        destination[p] = append[i];
        i++;
        p++;
    }
    return destination;
}

char *s21_strchr(char *string, char ch) {
    int i = 0;
    while (string[i] != ch) {
        i++;
    }
    return ch == string[i] ? (char *)string + i : NULL;
}

char *s21_strstr(char *strA, char *strB) {
    char *c = 0;
    while (*strA != '\0') {
        char *tempA = strA;
        char *tempB = strB;
        while (*tempA == *tempB) {
            tempA++;
            tempB++;
            if (*tempB == '\0') {
                c = strA;
            }
        }
        strA++;
    }
    return c;
}
