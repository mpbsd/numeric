#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PRECISION 12

void bconv(const int b, double f);

int main(void) {
  bconv(2, 0.02);
  exit(EXIT_SUCCESS);
}

void bconv(const int b, double f) {
  double epsilon = pow(0.1, PRECISION);

  double int_f; //   integral part of f
  double fra_f; // fractional part of f

  int sgn_f = 0;
  int *int_f_in_base_b = NULL;
  int fra_f_in_base_b[PRECISION] = {0};

  int i, e, n;

  if (f == 0.0) {
    printf("+0.");
    for (i = 0; i < PRECISION; i++)
      printf("0");
    printf("\n");
  } else {
    sgn_f = f / fabs(f);
    fra_f = modf(f, &int_f);
    int_f = fabs(int_f);
    fra_f = fabs(fra_f);
    n = (int)int_f;

    printf("%c", (sgn_f == 1) ? '+' : '-');

    if (int_f == 0) {
      printf("0");
    } else {
      for (i = 1, e = 0; i <= n; i *= b, e++)
        ;
      int_f_in_base_b = malloc(e * sizeof(int));
      for (i = e - 1; i >= 0; i--, n /= b)
        int_f_in_base_b[i] = n % b;
      for (i = 0; i <= e - 1; i++)
        printf("%d", int_f_in_base_b[i]);
      free(int_f_in_base_b);
    }

    printf(".");

    for (i = 0, f = 0.0; (i < PRECISION) && (fabs(f - fra_f) >= epsilon); i++) {
      n = (int)floor(pow(b, i + 1) * fra_f);
      fra_f_in_base_b[i] = (n >= b) ? b - 1 : n;
      f += fra_f_in_base_b[i] * pow(b, -(i + 1));
    }

    for (i = 0; i < PRECISION; i++)
      printf("%d", fra_f_in_base_b[i]);

    printf("\n");
  }
}
