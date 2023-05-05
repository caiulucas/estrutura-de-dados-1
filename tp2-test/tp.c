#include <stdio.h>
#include "sort.h"
#include "point.h"
#include "object.h"

int main() {
  int n;
  int pointsLength;

  scanf("%d %d", &n, &pointsLength);

  Object *objects = allocateObjects(n, pointsLength);
  readObjects(objects, n);

  for (int i = 0; i < n; i++)
  {
    objects[i].distance = calcDistances(&objects[i]);
    objects[i].displacement = calcDisplacement(&objects[i]);
  }

  shellSort(objects, n);
  printObjects(objects, n);
  freeObjects(&objects, n);
} 