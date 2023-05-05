#include <stdlib.h>
#include "tad.h"

TQuadrado *criarQuadrado(float x, float y, float escala) {
  TPonto origem = { x, y };
  TQuadrado *quadrado = (TQuadrado*) malloc(sizeof(TQuadrado));

  quadrado->origem = origem;
  quadrado->escala = escala;

  return quadrado;
}

void desalocaQuadrado(TQuadrado *quadrado) {
  free(quadrado);
}

TCirculo *criarCirculo(float x, float y, float raio) {
  TPonto origem = { x, y };
  TCirculo *circulo = (TCirculo*) malloc(sizeof(TCirculo));
  
  circulo->origem = origem;
  circulo->raio = raio;

  return circulo;
}

void desalocaCirculo(TCirculo *circulo) {
  free(circulo);
}