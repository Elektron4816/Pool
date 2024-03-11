#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

// /*
//     1 2 3
//     6 5 4
//     7 8 9
// */
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int n, m;
    int **result;
    int **matrix;

    input(matrix, &n, &m);

    sort_vertical(matrix, n, m, result);
    output(result, n, m);

    sort_horizontal(matrix, n, m, result);
    output(result, n,m);
    return 0;
}


void input(int **matrix, int *n, int *m) {
    scanf("%d", m);
    scanf("%d", n);
            **matrix = (int **)malloc( *n * sizeof(int *));
            for (int i = 0; i < *n; i++) {
                matrix[i] = (int *)malloc(*m * sizeof(int));
                for (int j = 0; j < *m; j++) {
                    scanf("%d", &matrix[i][j]);
                }
            }
            for (int i = 0; i < *n; i++) {
                for (int j = 0; j < *m; j++) {
                    printf("%1d ", matrix[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i < *n; i++) free(matrix[i]);
            free(matrix);
}
void output(int **matrix, int n, int m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%1d ", matrix[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i < n; i++) free(matrix[i]);
            free(matrix);

}

// void sort_vertical(int **matrix, int n, int m, int **result_matrix) {

    
// }

// void sort_horizontal(int **matrix, int n, int m, int **result_matrix)
// {

// }