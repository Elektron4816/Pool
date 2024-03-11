#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
  double *data = NULL;
  int n = 0;

  scanf("%d", &n);

  data = (double *)malloc(n * sizeof(double));
  int make_des;

  printf("LOAD DATA...\n");
  input(data, n);

  make_des = make_decision(data, n);

  printf("RAW DATA:\n\t");
  output(data, n);

  printf("\nNORMALIZED DATA:\n\t");
  normalization(data, n);
  output(data, n);

  printf("\nSORTED NORMALIZED DATA:\n\t");
  sort(data, n);
  output(data, n);

  printf("\nFINAL DECISION:\n\t");
  if (make_des) {
    printf("YES");
  } else {
    printf("NO");
  }
  free(data);
  return 0;
}
