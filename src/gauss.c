#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 3

void printsystem(double A[DIM][DIM], double b[DIM], char *header_msg);
void gauss(double A[DIM][DIM], double b[DIM], double *detA, int *info);

int main(void) {
  double A[DIM][DIM] = {
    {1.0, 2.0, 3.0},
    {4.0, 5.0, 6.0},
    {7.0, 8.0, 9.0}
  };
  double b[DIM] = {-3.0, -2.0, -1.0};
  double detA = 1.0;
  int info = 0;

  printsystem(A, b, "Sistema original");

  gauss(A, b, &detA, &info);

  printsystem(A, b, "Sistema escalonado");

  exit(EXIT_SUCCESS);
}

void printsystem(double A[DIM][DIM], double b[DIM], char *header_msg) {
  int i, j;
  printf("\n%s\n", header_msg);
  for (i = 0; i <= DIM - 1; i++) {
    printf("\n [");
    for (j = 0; j <= DIM + 1; j++) {
      if (j <= DIM - 1) {
        printf(" %6.2f", A[i][j]);
      } else if (j == DIM) {
        printf(" ][ X_%d ] = [", i);
      } else {
        printf(" %6.2f ]", b[i]);
      }
    }
  }
  printf("\n");
}

void gauss(double A[DIM][DIM], double b[DIM], double *detA, int *info) {
  int i, j, k, p;
  double Amax, mult, r, tmp;
  *detA = 1.0;
  *info = 0;
  for (j = 0; j <= DIM - 2; j++) {
    p = j;
    Amax = fabs(A[j][j]);
    for (k = j + 1; k <= DIM - 1; k++) {
      if (fabs(A[k][j]) > Amax) {
        Amax = fabs(A[k][j]);
        p = k;
      }
    }
    if (p != j) {
      for (k = 0; k <= DIM - 1; k++) {
        tmp = A[j][k];
        A[j][k] = A[p][k];
        A[p][k] = tmp;
      }
      tmp = b[j];
      b[j] = b[p];
      b[p] = tmp;
      *detA *= -1.0;
    }
    *detA *= A[j][j];
    if (fabs(A[j][j]) != 0) {
      r = 1.0 / A[j][j];
      for (i = j + 1; i <= DIM - 1; i++) {
        mult = A[i][j] * r;
        A[i][j] = 0.0;
        for (k = j + 1; k <= DIM - 1; k++) {
          A[i][k] -= mult * A[j][k];
        }
        b[i] -= mult * b[j];
      }
    } else {
      if (*info == 0) {
        *info = j;
      }
    }
  }
  *detA *= A[DIM - 1][DIM - 1];
  if (*info == 0 && fabs(A[DIM - 1][DIM - 1]) == 0) {
    *info = DIM - 1;
  }
}
