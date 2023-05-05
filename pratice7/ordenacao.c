#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n)
{
    int i, j, h;
    Aluno aux;

    for (h = 1; h < n; h = 3 * h + 1)
        ;

    for (; h > 0; h /= 3)
    {
        for (i = h; i < n; i++)
        {
            aux = alunos[i];
            j = i - h;
            while (j >= 0 && compare(alunos[j].nome, aux.nome) > 0)
            {
                alunos[j + h] = alunos[j];
                j -= h;
            }
            alunos[j + h] = aux;
        }
    }
}

// Manter como especificado
int compare(const char *aluno1, const char *aluno2)
{
    if (strcmp(aluno1, aluno2) < 0)
        return -1;
    else if (strcmp(aluno1, aluno2) == 0)
        return 0;
    else
        return 1;
}

/* Manter como especificado */
void imprimeResposta(Aluno *alunos, int n, int k)
{
    if(n > k)
        printf("%s\n", alunos[n - k].nome);
}

/* Manter como especificado */
Aluno *alocaAlunos(int n)
{
    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno **alunos)
{
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno *alunos, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int *n, int *k)
{
    scanf("%d %d", n, k);
}
