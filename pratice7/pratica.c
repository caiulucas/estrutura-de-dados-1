#include "ordenacao.h"
#include <stdio.h>

int main()
{
	int n, k;
	Aluno *alunos;

	// ler as quantidades
	leQuantidades(&n, &k);

	// alocar o vetor dinamico de alunos
	alunos = alocaAlunos(n);

	// preencher o vetor
	leAlunos(alunos, n);

	// ordenar o vetor usando o shellsort
	ordena(alunos, n);

	// imprimir a resposta
	imprimeResposta(alunos, n, k);

	// desalocar o vetor
	liberaAlunos(&alunos);

	return 0;
}
