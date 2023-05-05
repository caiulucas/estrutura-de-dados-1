#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    NAO = 0,
    SIM
} ESCALADO;

struct duende
{
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd)
{
    scanf("%d", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int n)
{
    Duende *duendes = (Duende *)malloc(n * sizeof(Duende));

    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int index)
{
    Duende *duende = (Duende *)malloc(sizeof(Duende));

    strcpy(duende->nome, duendes[index].nome);
    duende->idade = duendes[index].idade;
    duende->escalado = duendes[index].escalado;

    return duende;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes)
{
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n)
{
    int maisVelho = 0;
    for (int i = 0; i < n; i++)
    {
        if (duendes[i].escalado == NAO)
        {
            if (duendes[i].idade > duendes[maisVelho].idade || duendes[maisVelho].escalado == SIM)
            {
                maisVelho = i;
            }
        }
    }

    return maisVelho;
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index)
{
    duendes[index].escalado = SIM;
}

// Manter como especificado
void printDuende(Duende *duende)
{
    printf("%s %d\n", duende->nome, duende->idade);
}