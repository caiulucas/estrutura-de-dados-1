#include "ordenacao.h"
#include <stdio.h>

int main()
{
  int count = 1;
  // enquanto houver dados
  while (1)
  {
    int n;
    int time1, time2, pontos1, pontos2;
    int i, npartidas;
    Time *vetor;

    // leia o numero de times
    scanf("%d", &n);

    // se for zero, o programa acaba
    if (n == 0)
      return 1;

    // aloque o vetor
    vetor = alocaVetor(n);

    // calcula o numero de partidas
    npartidas = n * (n - 1) / 2;

    // para cada partida...
    for (i = 0; i < npartidas; i++)
    {
      scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

      // preencher o vetor de estruturas de acordo com os dados lidos
      int index1 = time1 - 1;
      int index2 = time2 - 1;

      vetor[index1].saldoPontos += pontos1;
      vetor[index2].saldoPontos += pontos2;

      vetor[index1].pontosSofridos += pontos2;
      vetor[index2].pontosSofridos += pontos1;

      if (pontos1 > pontos2)
      {
        vetor[index1].vitorias += 1;
        vetor[index2].derrotas += 1;
      }
      else
      {
        vetor[index1].derrotas += 1;
        vetor[index2].vitorias += 1;
      }
        }

    // ordenar os times
    quickSort(vetor, 0, n);

    // imprima o resultado
    printf("Instancia %d\n", count);
    for (i = 0; i < n; ++i)
    {
      printf("%d ", vetor[i].id);
    }
    printf("\n\n");

    // desaloque o vetor
    desalocaVetor(&vetor);
    count++;
  }

  return 0;
}
