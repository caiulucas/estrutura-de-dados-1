#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "object.h"

Object *allocateObjects(int n, int pointsLength) // Função para alocar dinamicamente o TAD
{
  Object *objects = (Object *)malloc(n * sizeof(Object));

  for (int i = 0; i < n; i++)
  {
    objects[i].pointsLength = pointsLength;
    objects[i].points = allocatePoints(pointsLength);
    objects[i].distance = 0;
    objects[i].displacement = 0;
  }
  return objects;
}

void freeObjects(Object **objects, int n) // Função para desalocar dinamicamente o TAD
{
  for (int i = 0; i < n; i++)
  {
    freePoints((*objects)[i].points);
  }
  free(*objects);
}

void readObjects(Object *objects, int n) // Função para ler o nome do objeto, quantos pontos e as trajetórias
{
  for (int i = 0; i < n; i++)
  {
    scanf("%s", objects[i].id);
    readPoints(objects[i].points, objects->pointsLength);
  }
}

double calcDistanceBetweenPoints(Point *point1, Point *point2) // Função para calcular a distância entre os pontos
{
  double distance = 0;
  distance += (point2->x - point1->x) * (point2->x - point1->x);
  distance += (point2->y - point1->y) * (point2->y - point1->y);
  distance = sqrt(distance);
  return distance;
}

double calcDistances(Object *object) // Função para calcular a distância percorrida
{
  double distance = 0;
  for (int i = 0; i < object->pointsLength - 1; i++)
  {
    distance += calcDistanceBetweenPoints(&object->points[i], &object->points[i + 1]);
  }
  return distance;
}

double calcDisplacement(Object *object) // Função para calcular o deslocamento
{
  return calcDistanceBetweenPoints(&object->points[0], &object->points[object->pointsLength - 1]);
}

void printObjects(Object *objects, int n) // Função para imprimir a lista dos objetos e suas respectivos desclocamentos e distâncias percorridas
{
  for (int i = 0; i < n; i++)
  {
    printf("%s %.2lf %.2lf\n", objects[i].id, objects[i].distance, objects[i].displacement);
  }
}

bool objectComp(Object *object1, Object *object2) // Função para comparar os objetos para esse serem organizados por Shellsort
{
  if (object1->distance < object2->distance)
    return true;
  else if (object1->displacement > object2->displacement)
    return false;
  else
  {
    if (strcmp(object1->id, object2->id) < 0)
      return true;
    else
      return false;
  }
}
return false;

}
