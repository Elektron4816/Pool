#include <stdio.h>
#include <stdlib.h>
#define V_MAX 100
#define G_MAX 100

int main() {
    int r;
    int **a;
    int i, j, n, m;
    scanf("%d", &r);

    switch (r) {
        case 1:
            scanf("%d", &n);
            scanf("%d", &m);
            int b[V_MAX][G_MAX];
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    scanf("%d", &b[i][j]);
                }
            }

            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            scanf("%d", &n);
            scanf("%d", &m);
            a = (int **)malloc(n * sizeof(int *));
            for (i = 0; i < n; i++) {
                a[i] = (int *)malloc(m * sizeof(int));
                for (j = 0; j < m; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%1d ", a[i][j]);
                }
                printf("\n");
            }
            for (i = 0; i < n; i++) free(a[i]);
            free(a);
            break;
        case 3:
            scanf("%d", &n);
            scanf("%d", &m);
            a = (int **)malloc(n * m * (sizeof(int)) + m * sizeof(int *));
            int *ptr = (int *)(a + n);
            for (int i = 0; i < n; i++) {
                a[i] = ptr + m * i;
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%1d ", a[i][j]);
                }
                printf("\n");
            }
            free(a);
            break;
        case 4:
            scanf("%d", &n);
            scanf("%d", &m);
            a = (int **)malloc(n * m * (sizeof(int)) + m * sizeof(int *));
            int *a_a = (int *)malloc(n * m * sizeof(int));
            for (int i = 0; i < n; i++) {
                a[i] = a_a + m * i;
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%1d ", a[i][j]);
                }
                printf("\n");
            }
            free(a);
            break;
        default:
            printf("n/a");
    }
    return 0;
}
