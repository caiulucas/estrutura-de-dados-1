#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende
{
  char nome[20];
  int idade;
  int escalado;
};

struct time
{
  char nomeLider[20];
  char nomeConfeiteiro[20];
  char nomeEntregador[20];
  char nomeEmbrulhador[20];
  int idadeLider;
  int idadeConfeiteiro;
  int idadeEntregador;
  int idadeEmbrulhador;
};

// Manter como especificado
void lerQuantidade(int *qtdDuendes)
{
  scanf("%d", qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes)
{
  return malloc(sizeof(Duende) * qtdDuendes);
}

// Manter como especificado
Time *alocaTimes(int qtdTimes)
{
  return malloc(sizeof(Time) * qtdTimes);
}

// Manter como especificado
void desalocaDuendes(Duende **duendes)
{
  free(*duendes);
}

// Manter como especificado
void desalocaTimes(Time **times)
{
  free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes)
{
  for (int i = 0; i < qtdDuendes; i++)
  {
    scanf("%s", duendes[i].nome);
    scanf("%d", &duendes[i].idade);
    duendes[i].escalado = NAO;
  }
}

// Manter como especificado
// Complexidade -> 3 * n ^ 2 - 3 * n
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes)
{
  int i, index;
  int qtdTime = qtdDuendes / 4;
  // Escalando os lideres

  for (i = 0; i < qtdTime; i++)
  {
    index = proximoMaisVelho(duendes, qtdDuendes);

    duendes[index].escalado = SIM;

    strcpy(times[i].nomeLider, duendes[index].nome);
    times[i].idadeLider = duendes[index].idade;
  }

  // Escalando os confeiteiros
  for (i = 0; i < qtdTime; i++)
  {
    index = proximoMaisVelho(duendes, qtdDuendes);

    duendes[index].escalado = SIM;
    strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
    times[i].idadeConfeiteiro = duendes[index].idade;
  }

  // Escalando os entregador
  for (i = 0; i < qtdTime; i++)
  {
    index = proximoMaisVelho(duendes, qtdDuendes);

    duendes[index].escalado = SIM;
    strcpy(times[i].nomeEntregador, duendes[index].nome);
    times[i].idadeEntregador = duendes[index].idade;
  }

  // Escalando os embrulhador
  for (i = 0; i < qtdTime; i++)
  {
    index = proximoMaisVelho(duendes, qtdDuendes);

    duendes[index].escalado = SIM;
    strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
    times[i].idadeEmbrulhador = duendes[index].idade;
  }
}

// Complexidade -> 3 * (n - 1)
int proximoMaisVelho(Duende *duendes, int qtdDuendes)
{
  int index = 0;

  for (int i = 1; i < qtdDuendes; i++)
  {
    if ((duendes[index].idade < duendes[i].idade && duendes[i].escalado == NAO) || duendes[index].escalado == SIM)
    {
      index = i;
    }
  }

  return index;
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes)
{
  for (int i = 0; i < qtdTimes; i++)
  {
    printf("Time %d\n", i + 1);
    printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
    printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
    printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
    printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
  }
}
