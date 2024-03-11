#include "s21_string.h"

#include <stdio.h>

#include "s21_string_test.h"
#define N 100

int main() {
#ifdef strlen_tests
    s21_strlen_test();
#endif

#ifdef strcmp_tests
    s21_strcmp_test();
#endif

#ifdef strcpy_tests
    s21_strcpy_test();
#endif

#ifdef strcat_tests
    s21_strcat_test();
#endif

#ifdef strchr_tests
    s21_strchr_test();
#endif

#ifdef strstr_tests
    s21_strstr_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char normal_value[N] = "Test normal string";
    int normal = 18;
    int normal_1 = s21_strlen(normal_value);
    printf("%s\n%d\n", normal_value, normal_1);
    if (normal_1 == normal) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char edge_value[N] = "";
    int edge = 0;
    int edge_1 = s21_strlen(edge_value);
    printf("%s\n%d\n", edge_value, edge_1);
    if (edge_1 == edge) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    char not_normal_value[N] = "\0";
    int not_normal = 1;
    int not_normal_1 = s21_strlen(not_normal_value);
    printf("%s\n%d\n", not_normal_value, not_normal_1);
    if (not_normal_1 == not_normal) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
void s21_strcmp_test() {
    char normal_value_1[N] = "qwerty";
    char normal_value_2[N] = "qwerty";
    int normal = 0;
    int normal_1 = s21_strcmp(normal_value_1, normal_value_2);
    printf("%s\n%s\n%d\n", normal_value_1, normal_value_2, normal_1);
    if (normal_1 == normal) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char edge_value_1[N] = "qwerty";
    char edge_value_2[N] = "";
    int edge = 0;
    int edge_1 = s21_strcmp(edge_value_1, edge_value_2);
    printf("%s\n%s\n%d\n", edge_value_1, edge_value_2, edge_1);
    if (edge_1 == edge) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char not_normal_value_1[N] = "qwerty";
    char not_normal_value_2[N] = "hello";
    int not_normal = 0;
    int not_normal_1 = s21_strcmp(not_normal_value_1, not_normal_value_2);
    printf("%s\n%s\n%d\n", not_normal_value_1, not_normal_value_2, not_normal_1);
    if (not_normal_1 == not_normal) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char normal_dest[N] = "Open";
    char normal_sour[N] = "";
    s21_strcpy(normal_sour, normal_dest);
    char *normal = "Open";
    int normal_1 = 0;
    printf("%s\n%s\n", normal_dest, normal_sour);
    if (s21_strcmp(normal_sour, normal) == normal_1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char edge_dest[N] = "Open\n";
    char edge_sour[N] = "";
    s21_strcpy(edge_sour, edge_dest);
    char *edge = "Open";
    int edge_1 = 0;
    printf("%s\n%s\n", edge_dest, edge_sour);
    if (s21_strcmp(edge_sour, edge) == edge_1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char not_normal_dest[N] = "Open";
    char not_normal_sour[N] = "";
    s21_strcpy(not_normal_sour, not_normal_dest);
    char *not_normal = "";
    int not_normal_1 = 0;
    printf("%s\n%s\n", not_normal_dest, not_normal_sour);
    if (s21_strcmp(not_normal_sour, not_normal) == not_normal_1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char normal_dest[N] = "String";
    char normal_app[N] = "Swap string";
    int len_a = s21_strlen(normal_app);
    s21_strcat(normal_app, normal_dest);
    printf("%s\n%s\n", normal_dest, normal_app);
    int len_b = s21_strlen(normal_dest);
    int len_ab = s21_strlen(normal_app);
    if (len_a + len_b == len_ab) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char edge_dest[N] = "String";
    char edge_app[N] = "Swap string";
    int edge_len_a = s21_strlen(edge_app);
    s21_strcat(edge_app, edge_dest);
    printf("%s\n%s\n", edge_dest, edge_app);
    int edge_len_b = s21_strlen(edge_dest);
    int edge_len_ab = s21_strlen(edge_app);
    if (edge_len_a + edge_len_b != edge_len_ab) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char not_normal_dest[N] = "String\n";
    char not_normal_app[N] = "Swap string";
    int ab = 17;
    s21_strcat(not_normal_app, not_normal_dest);
    printf("%s\n%s\n", not_normal_dest, not_normal_app);
    int not_len_ab = s21_strlen(not_normal_app);
    if (ab == not_len_ab) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strchr_test() {
    char normal_str[N] = "What a hell";
    char ch = 'a';
    char *c = s21_strchr(normal_str, ch);
    printf("%s\n%c\n%ld\n", normal_str, ch, c - normal_str + 1);
    if (*c == (char)ch) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char edge_str[N] = "What a hell";
    char edge_ch = '\0';
    char *edge_c = s21_strchr(edge_str, edge_ch);
    printf("%s\n%c\n%ld\n", edge_str, edge_ch, edge_c - edge_str + 1);
    if (*edge_c == (char)edge_ch) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char not_normal_str[N] = "What a hell";
    char not_ch = ' ';
    char *not_c = s21_strchr(not_normal_str, not_ch);
    printf("%s\n%c\n%ld\n", not_normal_str, not_ch, not_c - not_normal_str + 1);
    if (*not_c == (char)not_ch) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    char normal_strA[N] = "Congratulation";
    char normal_strB[N] = "tul";
    char *str = (s21_strstr(normal_strA, normal_strB));
    printf("%s\n%ld\n", normal_strA, str - normal_strA + 1);
    if (str - normal_strA != 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char edge_strA[N] = "Congratulation";
    char edge_strB[N] = "1";
    char *edge_str = (s21_strstr(edge_strA, edge_strB));
    printf("%s\n%s\n", edge_strA, edge_str);
    if (edge_str - edge_strA == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char not_normal_strA[N] = "Congratulation";
    char not_normal_strB[N] = "zex";
    char *not_str = (s21_strstr(not_normal_strA, not_normal_strB));
    printf("%s\n%s\n", not_normal_strA, edge_str);
    if (not_str - not_normal_strA == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}
