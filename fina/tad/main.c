#include <stdio.h>
#include "tad.h"

int main() {
  TQuadrado *q = criarQuadrado(2, 3, 5);
  TCirculo *c = criarCirculo(1, 4, 10);

  printf("Quadrado X -> %f, Y -> %f, h -> %f\n", q->origem.x, q->origem.y, q->escala);
  printf("Circulo X-> %f, Y -> %f, r -> %f\n", c->origem.x, c->origem.y, c->raio);

  desalocaQuadrado(q);
  desalocaCirculo(c);
}