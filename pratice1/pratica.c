#include "matriz.h"
#include<stdio.h>

int main()
{
    double **M, resultado;
    int ordem;
    char operacao;

    lerOrdem(&ordem);
    lerOperacao(&operacao);
    M = alocaMatriz(ordem);
    lerMatriz(M, ordem);
    resultado = somaMatriz(M, ordem);
    if(operacao == 'M')
      resultado = media(resultado, ordem);
    printResultado(resultado);
    desalocaMatriz(&M, ordem);
    
    return 0;//nao remova
}
