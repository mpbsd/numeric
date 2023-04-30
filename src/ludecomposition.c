#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DIM 3


void print_system_of_equations(double A[DIM][DIM], char *header_msg);
void lu_decomposition(double A[DIM][DIM], int pivot[DIM], double *PdU, int *Info, double L[DIM][DIM], double U[DIM][DIM], double P[DIM][DIM]);
void matrix_product(double X[DIM][DIM], double Y[DIM][DIM], double prodXY[DIM][DIM]);
void error_checking(double A[DIM][DIM], double L[DIM][DIM], double U[DIM][DIM], double P[DIM][DIM]);


int main(void) {
  double A[DIM][DIM] = {
    {1.0, -3.0, 2.0},
    {-2.0, 8.0, -1.0},
    {4.0, -6.0, 5.0}
  };
  /* double b[DIM] = {11.0, -15.0, 29.0}; */
  int pivot[DIM];
  double L[DIM][DIM] = {{0.0}};
  double U[DIM][DIM] = {{0.0}};
  double P[DIM][DIM] = {{0.0}};
  double PdU;
  int Info;

  print_system_of_equations(A, "matrix de coeficientes, A:");

  lu_decomposition(A, pivot, &PdU, &Info, L, U, P);

  error_checking(A, L, U, P);

  exit(EXIT_SUCCESS);
}



void print_system_of_equations(double A[DIM][DIM], char *header_msg) {
  int i, j;
  printf("\n%s\n", header_msg);
  for (i = 0; i <= DIM - 1; i++) {
    printf("\n");
    for (j = 0; j <= DIM - 1; j++) {
      if (j == 0) {
        printf("[ %6.2f", A[i][j]);
      } else if (j <= DIM - 2) {
        printf(" %6.2f", A[i][j]);
      } else {
        printf(" %6.2f ]", A[i][j]);
      }
    }
  }
  printf("\n");
}



void lu_decomposition(double A[DIM][DIM], int pivot[DIM], double *PdU, int *Info, double L[DIM][DIM], double U[DIM][DIM], double P[DIM][DIM]) {
  int i, j, k, p;
  double Amax, tmp, r, mult;
  for (i = 0; i <= DIM - 1; i++) {
    pivot[i] = i;
  }
  *PdU = 1.0;
  *Info = 0;
  for (j = 0; j <= DIM - 1; j++) {
    p = j;
    Amax = fabs(A[j][j]);
    for (k = j + 1; k <= DIM; k++) {
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
      i = pivot[j];
      pivot[j] = pivot[p];
      pivot[p] = i;
      *PdU *= 1.0;
    }
    *PdU *= A[j][j];
    if (fabs(A[j][j]) != 0) {
      r = 1.0 / A[j][j];
      for (i = j + 1; i <= DIM - 1; i++) {
        mult = A[i][j] *  r;
        A[i][j] = mult;
        for (k = j + 1; k <= DIM - 1; k++) {
          A[i][k] -= mult * A[j][k];
        }
      }
    } else {
      if (*Info == 0) {
        *Info = j;
      }
    }
  }
  for (i = 0; i <= DIM - 1; i++) {
    for (j = 0; j <= DIM - 1; j++) {
      if (i < j) {
        U[i][j] = A[i][j];
      } else if (i == j) {
        U[i][j] = A[i][j];
        L[i][j] = 1.0;
      } else {
        L[i][j] = A[i][j];
      }
      if (pivot[i] == j) {
        P[i][j] = 1.0;
      }
    }
  }
  print_system_of_equations(L, "matriz triangular inferior, L:");
  print_system_of_equations(U, "matriz triangular superior, U:");
  print_system_of_equations(P, "matriz de permutação, P:");
}


void matrix_product(double X[DIM][DIM], double Y[DIM][DIM], double prodXY[DIM][DIM]) {
  int i, j, k;
  double Z[DIM][DIM] = {{0.0}};
  for (i = 0; i <= DIM - 1; i++) {
    for (j = 0; j <= DIM - 1; j++) {
      for (k = 0; k <= DIM - 1; k++) {
        Z[i][j] += X[i][k] * Y[k][j];
      }
      prodXY[i][j] = Z[i][j];
    }
  }
}


void error_checking(double A[DIM][DIM], double L[DIM][DIM], double U[DIM][DIM], double P[DIM][DIM]) {
  double V[DIM][DIM] = {{0.0}};
  double W[DIM][DIM] = {{0.0}};
  int i, j;
  matrix_product(L, U, V);
  matrix_product(P, V, V);
  print_system_of_equations(W, "buscando por possíveis erros, A - P * L * U:");
  for (i = 0; i <= DIM - 1; i++) {
    for (j = 0; j <= DIM - 1; j++) {
      W[i][j] = A[i][j] - V[i][j];
    }
  }
}
