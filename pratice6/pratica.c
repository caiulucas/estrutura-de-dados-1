#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int *vetor;
	int i, n, movimentos;
	while(scanf("%d", &n), n)
	{
		//alocar o vetor
		vetor = alocaVetor(vetor, n);
		//preencher o vetor
		for(i = 0; i < n; i++)
			scanf("%d", &vetor[i]);
		//ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor, n, &movimentos);
		
		movimentos % 2 == 0 ? printf("Carlos\n") : printf("Marcelo\n");

		//desalocar o vetor
		vetor = desalocaVetor(vetor);

	}

	return 0;
}
