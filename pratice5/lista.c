#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    pLista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    pLista->ultimo->prox->item = item;
    pLista->ultimo = pLista->ultimo->prox;
    pLista->ultimo->prox = NULL;
    return true;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    Celula *aux = pLista->cabeca->prox;
    pLista->cabeca->prox = (Celula*) malloc(sizeof(Celula));
    pLista->cabeca->prox->item = item;
    pLista->cabeca->prox->prox = aux;
    
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    if(ListaEhVazia(pLista))
        return false;

    Celula *aux = pLista->cabeca->prox;
    *pItem = aux->item;
    pLista->cabeca->prox = aux->prox;
    free(aux);
    return true;
}

void ListaLibera(Lista* pLista) {
    while(!ListaEhVazia(pLista)) {
        printf("fasd");
        ListaRetiraPrimeiro(pLista, NULL);
    }
}