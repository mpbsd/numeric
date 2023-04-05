#include <stdio.h>
#include <stdlib.h>

void bconv(const unsigned int base, int num);

int main(int argc, char **argv)
{
  int base, num;

  if (argc == 3) {
    base = atoi(argv[1]);
    num = atoi(argv[2]);
    bconv(base, num);
  } else {
    printf("help message\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}

/* bconv: decimal --> base */
void bconv(const unsigned int base, int num)
{
  int i, exp;
  int *num_in_base = NULL;

  for (i = base, exp = 1; i <= num; i *= base) {
    exp++;
  }

  num_in_base = malloc(exp * sizeof(int));

  for (i = exp - 1; i >= 0; i--, num /= base) {
    num_in_base[i] = num % base;
  }

  for (i = 0; i <= exp - 1; i++) {
    printf("%d", num_in_base[i]);
  }

  printf("\n");

  free(num_in_base);
}
