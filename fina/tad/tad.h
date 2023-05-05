#pragma once

typedef struct {
  float x;
  float y;
} TPonto;

typedef struct {
  TPonto origem;
  float escala;
} TQuadrado;

typedef struct {
  TPonto origem;
  float raio;
} TCirculo;

TQuadrado *criarQuadrado(float x, float y, float escala);

void desalocaQuadrado(TQuadrado *quadrado);

TCirculo *criarCirculo(float x, float y, float raio);

void desalocaCirculo(TCirculo *circulo);