#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N               3
#define MAX_ERROR 0.00001
#define MAX_STEPS      50

int A_is_diagonally_dominant(double A[N][N]);
void jacobi_stationaty_method(double A[N][N], double b[N], double x[N], int *steps, int *info);
void gauss_seidel_stationaty_method(double A[N][N], double b[N], double x[N], int *steps, int *info);

int main(void) {
  double A[N][N] = {
    {10.0, 3.0, -2.0},
    { 2.0, 8.0, -1.0},
    { 1.0, 1.0,  5.0}
  };
  double b[N] = {57.0, 20.0, -4.0};
  double x[N];
  int steps, info, i;

  if (A_is_diagonally_dominant(A) == 1) {
    printf("Jacobi method:\n");
    for (i = 0; i <= N - 1; i++) {
      if (i == 0) {
        printf("\nIter %d     x_%d", i, i);
      } else if (i == N - 1) {
        printf("          x_%d          Relative norm\n", i);
      } else {
        printf("          x_%d", i);
      }
    }
    jacobi_stationaty_method(A, b, x, &steps, &info);
    printf("\nGauss-Seidel method:\n");
    steps = 0;
    info = 1;
    for (i = 0; i <= N - 1; i++) {
      if (i == 0) {
        printf("\nIter %d     x_%d", i, i);
      } else if (i == N - 1) {
        printf("          x_%d          Relative norm\n", i);
      } else {
        printf("          x_%d", i);
      }
    }
    gauss_seidel_stationaty_method(A, b, x, &steps, &info);
  }

  exit(EXIT_SUCCESS);
}

int A_is_diagonally_dominant(double A[N][N]) {
  double sum;
  int B[N], b = 1, i, j;
  for (i = 0; i <= N - 1; i++) {
    sum = 0.0;
    for (j = 0; j <= N - 1; j++) {
      if (i != j) {
        sum += fabs(A[i][j]);
      }
    }
    B[i] = (fabs(A[i][i]) > sum) ? 1 : 0;
  }
  for (i = 0; i <= N - 1; i++) {
    b *= B[i];
  }
  return b;
}

void jacobi_stationaty_method(double A[N][N], double b[N], double x[N], int *steps, int *info) {
  double sum, t, v[N], normNum, normDen, normRel;
  int i, j;
  for (i = 0; i <= N - 1; i++) {
    x[i] = b[i] / A[i][i];
  }
  *steps = 0;
  do {
    (*steps)++;
    for (i = 0; i <= N - 1; i++) {
      sum = 0.0;
      for (j = 0; j <= N - 1; j++) {
        if ( i != j) {
          sum += A[i][j] * x[j];
        }
      }
      v[i] = (b[i] - sum) / A[i][i];
    }
    normNum = 0.0;
    normDen = 0.0;
    for (i = 0; i <= N - 1; i++) {
      t = fabs(v[i] - x[i]);
      if (t > normNum) {
        normNum = t;
      }
      if (fabs(v[i]) > normDen) {
        normDen = fabs(v[i]);
      }
      x[i] = v[i];
    }
    normRel = normNum / normDen;
    for (i = 0; i <= N - 1; i++) {
      if (i == 0) {
        printf("%6d %12.6f", *steps, x[i]);
      } else if (i == N - 1) {
        printf(" %12.6f %12.6f\n", x[i], normRel);
      } else {
        printf(" %12.6f", x[i]);
      }
    }
  } while ((normRel >= MAX_ERROR) && (*steps <= MAX_STEPS));
  if (normRel <= MAX_ERROR) {
    *info = 0; /* 0 means the answer is within range in at most MAX_STEPS */
  } else {
    *info = 1; /* 1 means the answer isn't within range in at most MAX_STEPS */
  }
}

void gauss_seidel_stationaty_method(double A[N][N], double b[N], double x[N], int *steps, int *info) {
  double sum, t, v[N], normNum, normDen, normRel;
  int i, j;
  for (i = 0; i <= N - 1; i++) {
    x[i] = b[i] / A[i][i];
  }
  *steps = 0;
  do {
    (*steps)++;
    normNum = 0.0;
    normDen = 0.0;
    for (i = 0; i <= N - 1; i++) {
      sum = 0.0;
      for (j = 0; j <= N - 1; j++) {
        if (i != j) {
          sum += A[i][j] * x[j];
        }
      }
      v[i] = x[i];
      x[i] = (b[i] - sum) / A[i][i];
      t = fabs(v[i] - x[i]);
      if (t > normNum) {
        normNum = t;
      }
      if (fabs(x[i]) > normDen) {
        normDen = fabs(x[i]);
      }
    }
    normRel = normNum / normDen;
    for (i = 0; i <= N - 1; i++) {
      if (i == 0) {
        printf("%6d %12.6f", *steps, x[i]);
      } else if (i == N - 1) {
        printf(" %12.6f %12.6f\n", x[i], normRel);
      } else {
        printf(" %12.6f", x[i]);
      }
    }
  } while((normRel >= MAX_ERROR) && ((*steps) <= MAX_STEPS));
  if (normRel <= MAX_ERROR) {
    *info = 0; /* 0 means the answer is within range in at most MAX_STEPS */
  } else {
    *info = 1; /* 1 means the answer isn't within range in at most MAX_STEPS */
  }
}
