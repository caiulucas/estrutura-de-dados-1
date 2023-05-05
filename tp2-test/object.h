#pragma once
#include <stdbool.h>
#include "point.h"

typedef struct
{
  char id[5];
  int pointsLength;
  Point *points;
  double distance;
  double displacement;
} Object;

Object *allocateObjects(int n, int pointsLength);

void freeObjects(Object **objects, int n);

void readObjects(Object *objects, int n);

double calcDistances();

double calcDisplacement();

void printObjects(Object *objects, int n);

bool objectComp(Object *object1, Object *object2);
