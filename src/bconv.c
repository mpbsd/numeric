#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PRECISION 16
#define EPSILON pow(0.1, PRECISION)

typedef struct {
  int *integer_part;
  int integer_part_size;
  int fractional_part[PRECISION];
} real_number_t;

void bconv(const int b, const double f, real_number_t *x);
void print(const real_number_t x);

int main(void)
{
  real_number_t x[2] = {{NULL, 0, {0}}};
  bconv(2, 0.6, &x[0]);
  bconv(2, 0.7, &x[1]);
  print(x[0]);
  print(x[1]);
  free(x[0].integer_part);
  free(x[1].integer_part);
  exit(EXIT_SUCCESS);
}

/* 
 * I think there's a bug in bconv where it does not correctly convert numbers
 * to bases with more than 10 symbols. I'll fix it in future versions.
 */
void bconv(const int b, const double f, real_number_t *x)
{
  double int_f, fra_f, aprox_fra_f;
  int n, i;
  fra_f = modf(f, &int_f);
  n = (int)int_f;
  if (n == 0) {
    x->integer_part = 0;
  } else {
    for (i = 1, x->integer_part_size = 0; i <= n; i *= b, (x->integer_part_size)++)
      ;
    x->integer_part = malloc((x->integer_part_size) * sizeof(int));
    for (i = (x->integer_part_size) - 1; i >= 0; i--, n /= b) {
      x->integer_part[i] = n % b;
    }
  }
  for (i = 1, aprox_fra_f = 0.0; (i < PRECISION) && (fabs(aprox_fra_f - fra_f) >= EPSILON); i++) {
    x->fractional_part[i] = (int)floor(pow(b, i) * fabs(fra_f - aprox_fra_f));
    aprox_fra_f += x->fractional_part[i] * pow(b, -i);
  }
}

void print(const real_number_t x)
{
  int i;
  printf("\n");
  for (i = 0; i < (x.integer_part_size); i++) {
    printf("%d", x.integer_part[i]);
  }
  printf(".");
  for (i = 0; i < PRECISION; i++) {
    printf("%d", x.fractional_part[i]);
  }
  printf("\n");
}
