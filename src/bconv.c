#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NBASE     2
#define PRECISION 16
#define EPSILON   pow(0.1, PRECISION)

void bconv(const int b, double f);

int main(void) {
  bconv(NBASE, 0.6);
  bconv(NBASE, 0.7);
  exit(EXIT_SUCCESS);
}

void bconv(const int b, double f) {
  double int_f;
  double fra_f;
  int *int_f_in_nbase = NULL;
  int fra_f_in_nbase[PRECISION] = {0};
  double aprox_fra_f;
  int n, i, e;

  fra_f = modf(f, &int_f);

  n = (int)int_f;

  if (n == 0) {
    printf("0");
  } else {
    for (i = 1, e = 0; i <= n; i *= b, e++)
      ;
    int_f_in_nbase = malloc(e * sizeof(int));
    for (i = e - 1; i >= 0; i--, n /= b)
      int_f_in_nbase[i] = n % b;
    for (i = 0; i < e; i++)
      printf("%d", int_f_in_nbase[i]);
    free(int_f_in_nbase);
  }

  printf(".");

  for (i = 1, aprox_fra_f = 0.0; (i < PRECISION) && (fabs(aprox_fra_f - fra_f) >= EPSILON); i++) {
    fra_f_in_nbase[i] = (int)floor(pow(b, i) * fabs(fra_f - aprox_fra_f));
    aprox_fra_f += fra_f_in_nbase[i] * pow(b, -i);
  }

  for (i = 1; i < PRECISION; i++) {
    printf("%d", fra_f_in_nbase[i]);
  }

  printf("\n");
}
