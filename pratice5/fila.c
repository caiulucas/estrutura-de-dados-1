#include "fila.h"
#include "pilha.h"
#include <stdlib.h>

bool FilaInicia(Fila* pFila) {
    return ListaInicia(pFila); 
}

bool FilaEnfileira(Fila* pFila, Item item) {
    return ListaInsereInicio(pFila, item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    if(FilaEhVazia(pFila)) {
        return false;
    }

    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila* pFila) {
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    ListaLibera(pFila);
}

bool FilaInverte(Fila* pFila) {
    Pilha pilha;
    PilhaInicia(&pilha);

    Item item;
    while(FilaDesinfeleira(pFila, &item)) {
        PilhaPush(&pilha, item);
    }

    while(PilhaPop(&pilha, &item)) {
        FilaEnfileira(pFila, item);
    }

    PilhaLibera(&pilha);
    return true;
}
