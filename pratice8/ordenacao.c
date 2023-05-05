#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

// Manter como especificado
Time *alocaVetor(int n)
{
  Time *vetor = (Time *)malloc(n * sizeof(Time));

  for (int i = 0; i < n; i++)
  {
    vetor[i].id = i + 1;
    vetor[i].vitorias = 0;
    vetor[i].derrotas = 0;
    vetor[i].saldoPontos = 0;
    vetor[i].pontosSofridos = 0;
  }
  return vetor;
}

// Manter como especificado
void desalocaVetor(Time **vetor)
{
  free(*vetor);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare

void heapRefaz(Time *vetor, int esq, int dir)
{
  int i = esq;
  int j = i * 2 + 1;
  Time aux = vetor[i];

  while (j <= dir)
  {
    if (j < dir && compare(vetor[j], vetor[j + 1]))
      j++;

    if (!compare(aux, vetor[j]))
      break;

    vetor[i] = vetor[j];
    i = j;
    j = i * 2 + 1;
  }
  vetor[i] = aux;
}

void heapBuild(Time *vetor, int n)
{
  int esq = n / 2 - 1;

  while (esq >= 0)
  {
    heapRefaz(vetor, esq, n - 1);
    esq--;
  }
}

void heapSort(Time *vetor, int n)
{
  heapBuild(vetor, n);
  Time aux = vetor[0];

  while (n > 1)
  {
    aux = vetor[n - 1];
    vetor[n - 1] = vetor[0];
    vetor[0] = aux;
    n--;
    heapRefaz(vetor, 0, n - 1);
  }
}

void merge(Time *vetor, int left, int mid, int right)
{
  int sizeLeft = mid - left + 1;
  int sizeRight = right - mid;

  Time *vLeft = alocaVetor(sizeLeft);
  Time *vRight = alocaVetor(sizeRight);

  for (int i = 0; i < sizeLeft; i++)
  {
    vLeft[i] = vetor[i + left];
  }

  for (int i = 0; i < sizeRight; i++)
  {
    vRight[i] = vetor[i + mid];
  }

  int i = 0;
  int j = 0;

  for (int k = left; k < right; k++)
  {
    if (i == sizeLeft)
    {
      vetor[k] = vRight[j++];
    }
    else if (j == sizeRight)
    {
      vetor[k] = vLeft[i++];
    }
    else if (compare(vLeft[i], vRight[j]))
    {
      vetor[k] = vLeft[i++];
    }
    else
    {
      vetor[k] = vRight[j++];
    }
  }

  desalocaVetor(&vLeft);
  desalocaVetor(&vRight);
}

void mergeSort(Time *vetor, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    mergeSort(vetor, left, mid);
    mergeSort(vetor, mid + 1, right);
    merge(vetor, left, mid, right);
  }
}

int partition(Time *vetor, int left, int right)
{
  Time pivot = vetor[right];
  int i = left - 1;

  for (int j = left; j < right; j++)
  {
    if (compare(vetor[j], pivot))
    {
      i++;
      Time aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
    }
  }

  Time aux = vetor[i + 1];
  vetor[i + 1] = vetor[right];
  vetor[right] = aux;

  return i + 1;
}

void quickSort(Time *vetor, int left, int right)
{
  if (left < right)
  {
    int index = partition(vetor, left, right);
    quickSort(vetor, left, index - 1);
    quickSort(vetor, index + 1, right);
  }
}


// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2)
{
  int pts1 = t1.vitorias * 2 + t1.derrotas;
  int pts2 = t2.vitorias * 2 + t2.derrotas;

  if (pts1 > pts2)
    return 1;
  else if (pts1 == pts2)
  {
    float ptsRazao1 = t1.pontosSofridos ? (float)t1.saldoPontos / t1.pontosSofridos : t1.saldoPontos;
    float ptsRazao2 = t2.pontosSofridos ? (float)t2.saldoPontos / t2.pontosSofridos : t2.saldoPontos;

    if (ptsRazao1 > ptsRazao2)
      return 1;
    else if (ptsRazao1 == ptsRazao2)
    {
      if (t1.saldoPontos > t2.saldoPontos)
        return 1;
      else if (t1.saldoPontos == t2.saldoPontos)
      {
        if (t1.id < t2.id)
          return 1;
      }
    }
  }

  return 0;
}
