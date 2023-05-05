#include <stdlib.h>
#include <string.h>
#include "sort.h"

void shellSort(Object *objects, int n)  // Função para organizar a listagem dos objetos e suas informções de acordo com as regras impostas por Shellsort
{
  Object v;

  int i, j;
  int h = 1;
  while (h < n)
    h = 3 * h + 1;
  for (; h > 0; h /= 3)
    for (i = h; i < n; i++)
    {
      v = objects[i];
      j = i - h;
      while (j >= 0 && objectComp(&objects[j], &v))
      {
        objects[j + h] = objects[j];
        j -= h;
      }
      objects[j + h] = v;
    }
}