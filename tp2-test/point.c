#include <stdio.h>
#include <stdlib.h>
#include "point.h"

Point *allocatePoints(int n) // Função para alocar dinamicamente os pontos
{
  Point *points = (Point *)malloc(n * sizeof(Point));
  return points;
}

void freePoints(Point *points) // Função para desalocar dinamicamente os pontos
{
  free(points);
}

void readPoints(Point *points, int n) // Função para ler as coordenadas de cada ponto
{
  for (int i = 0; i < n; i++)
  {
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }
}