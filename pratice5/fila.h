#ifndef FILA_H
#define FILA_H

#include "lista.h"

typedef Lista Fila;

/* Manter como especificado */
bool FilaInicia(Fila*);

/* Manter como especificado */
bool FilaEnfileira(Fila*, Item);

/* Manter como especificado */
bool FilaDesinfeleira(Fila*, Item*);

/* Manter como especificado */
bool FilaEhVazia(Fila*);

/* Manter como especificado */
void FilaLibera(Fila*);

/* Manter como especificado */
bool FilaInverte(Fila*);

#endif // !FILA_H