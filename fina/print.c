#include <stdio.h>

// T(n) = n + T(n - 1)
// T(1) = 1
void imprime(int *v, int n)
{
  if (n > 1)
  {
    imprime(v, n - 1);
  }

  printf("%d ", v[n - 1]);
}

void imprime_reverso(int *v, int n)
{
  printf("%d ", v[n - 1]);

  if (n > 1)
  {
    imprime_reverso(v, n - 1);
  }
}