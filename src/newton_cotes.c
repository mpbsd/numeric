#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592

void newtonCotes(double a, double b, int n, int m);

int main(void) {
  newtonCotes(0.0, PI, 1, 24);
  newtonCotes(0.0, PI, 2, 24);
  newtonCotes(0.0, PI, 3, 24);
  exit(EXIT_SUCCESS);
}

void newtonCotes(double a, double b, int n, int m) {
  int *c = malloc((n * m) * sizeof(int));
  double I = 0.0;
  double h = (b - a) / (n * m);
  int i;
  if (n == 1) {
    for (i = 0; i <= m - 1; ++i) {
      if ((i == 0) || (i == m - 1)) {
        c[i] = 1;
      } else {
        c[i] = 2;
      }
      I += c[i] * sin(a + i * h);
    }
    I *= h / 2.0;
  } else if (n == 2) {
    for (i = 0; i <= 2 * (m - 1); ++i) {
      if ((i == 0) || (i == 2 * (m - 1))) {
        c[i] = 1;
      } else if (i % 2 == 1) {
        c[i] = 4;
      } else {
        c[i] = 2;
      }
      I += c[i] * sin(a + i * h);
    }
    I *= h / 3.0;
  } else if (n == 3) {
    for (i = 0; i <= 3 * (m - 1); ++i) {
      if ((i == 0) || (i == 3 * (m - 1))) {
        c[i] = 1;
      } else if (i % 3 != 0) {
        c[i] = 3;
      } else {
        c[i] = 2;
      }
      I += c[i] * sin(a + i * h);
    }
    I *= (3.0 / 8.0) * h;
  }
  printf("Approximate integral: %f, n = %d, m = %d\n", I, n, m);
  free(c);
}
