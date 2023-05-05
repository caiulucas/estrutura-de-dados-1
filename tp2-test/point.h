#pragma once

typedef struct
{
  double x;
  double y;
} Point;

Point *allocatePoints(int n);

void freePoints(Point *points);

void readPoints(Point *points, int n);

