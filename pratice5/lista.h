#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct {
    char nome[31];
} Item;

typedef struct cel {
    Item item;
    struct cel* prox;    
} Celula;

typedef struct {
    Celula* cabeca;
    Celula* ultimo;
} Lista;

/* Manter como especificado */
bool ListaInicia(Lista*);

/* Manter como especificado */
bool ListaEhVazia(Lista*);

/* Manter como especificado */
bool ListaInsereFinal(Lista*, Item);

/* Manter como especificado */
bool ListaInsereInicio(Lista*, Item);

/* Manter como especificado */
bool ListaRetiraPrimeiro(Lista*, Item*);

/* Manter como especificado */
void ListaLibera(Lista*);

#endif // !LISTA_H