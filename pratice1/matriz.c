#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void lerOrdem(int *ordem) {
  scanf("%d", ordem);
}

//manter como especificado
double **alocaMatriz(int ordem) {
  double **matriz = malloc(ordem * sizeof(double*));

  for(int i = 0; i < ordem; i++) 
    matriz[i] = malloc(ordem * sizeof(double));

  return matriz;
}

//manter como especificado
void desalocaMatriz(double ***M, int ordem) {
  for(int i = 0; i < ordem; i++) free((*M)[i]);

  free(*M);  
}

//manter como especificado
void lerOperacao(char *operacao) {
  scanf(" %c", operacao);
}

void lerMatriz(double **M, int ordem) {
  for(int i = 0; i < ordem; i++) {
    for(int j = 0; j < ordem; j++) {
      scanf("%lf", &M[i][j]);
    }
  }
}

double somaMatriz(double **M, int ordem) {
  double soma = 0;
  int cont = 1;

  for(int i = 0; i < ordem / 2 - 1; i++) {
    for(int j = cont; j < ordem; j++) {
      if (j == ordem - cont) break;

      soma += M[i][j];
    }
    cont++;
  }

  return soma;
}

double media(double resultado, int ordem) {
  int cont = 1;
  int div = 0;

  for(int i = 0; i < ordem / 2 - 1; i++) {
    for(int j = cont; j < ordem; j++) {
      if (j == ordem - cont) break;
      div++;
    }
    cont++;
  }

  return resultado / div;
}

void printResultado(double resultado) {
  printf("%0.1lf", resultado);
}
