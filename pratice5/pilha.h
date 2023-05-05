#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

typedef Lista Pilha;

/* Manter como especificado */
bool PilhaInicia(Pilha*);

/* Manter como especificado */
bool PilhaPush(Pilha*, Item);

/* Manter como especificado */
bool PilhaPop(Pilha*, Item*);

/* Manter como especificado */
bool PilhaEhVazia(Pilha*);

/* Manter como especificado */
void PilhaLibera(Pilha*);

#endif // !PILHA_H