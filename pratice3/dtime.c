#include "dtime.h"
#include "duende.h"
#include <stdio.h>
#include <stdlib.h>

struct time
{
    Duende *lider;
    Duende *piloto;
    Duende *entregador;
};

// Manter como especificado
Time *alocaTimes(int n)
{
    Time *times = (Time *)malloc(n * sizeof(Time));

    return times;
}

// Manter como especificado
void desalocaTimes(Time **times, int n)
{
    for (int i = 0; i < n; i++)
    {
        desalocaDuendes(&(*times)[i].lider);
        desalocaDuendes(&(*times)[i].piloto);
        desalocaDuendes(&(*times)[i].entregador);
    }
    free(*times);
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes)
{
    int i, index;
    int qtdTime = qtdDuendes / 3;
    // Escalando os lideres
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        escalarDuende(duendes, index); 
        times[i].lider = copiaDuende(duendes, index);
    }

    // Escalando os pilotos
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        escalarDuende(duendes, index); 
        times[i].piloto = copiaDuende(duendes, index);
    }

    // Escalando os entregadores
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        escalarDuende(duendes, index); 
        times[i].entregador = copiaDuende(duendes, index);
    }
}

// Manter como especificado
void printTimes(Time *times, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("Time %d\n", i + 1);
        printf("[L] ");
        printDuende(times[i].lider);
        printf("[P] ");
        printDuende(times[i].piloto);
        printf("[E] ");
        printDuende(times[i].entregador);
        printf("\n");
    }
}
