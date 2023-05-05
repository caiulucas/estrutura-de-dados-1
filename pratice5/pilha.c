#include <stdlib.h>
#include "pilha.h"

bool PilhaInicia(Pilha* pPilha) {
    ListaInicia(pPilha);
}

bool PilhaPush(Pilha* pPilha, Item item) {
    return ListaInsereInicio(pPilha, item);
}

bool PilhaPop(Pilha* pPilha, Item* pItem) {
    if(PilhaEhVazia(pPilha)) {
        return false;
    }

    return ListaRetiraPrimeiro(pPilha, pItem);
}


bool PilhaEhVazia(Pilha* pPilha) {
    return ListaEhVazia(pPilha);
}

void PilhaLibera(Pilha* pPilha) {
    ListaLibera(pPilha);
}