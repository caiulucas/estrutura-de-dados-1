#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
  vetor = malloc(n * sizeof(int));
  return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
  free(vetor);
  return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
  int i, j, aux;
  *movimentos = 0;
  
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      if(vetor[i] > vetor[j]){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
        *movimentos += 1;
      }
    }
  }
}
