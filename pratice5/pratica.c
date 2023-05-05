#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void FilaImprime(Fila*);

int main() {
    int n;
    Fila fila;
    Item item;
    FilaInicia(&fila);
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", item.nome);
        FilaEnfileira(&fila, item);
    }
    FilaInverte(&fila);
    FilaImprime(&fila);
    FilaLibera(&fila);
    return 0;
}

void FilaImprime(Fila* pFila) {
    for(Celula* atual=pFila->cabeca->prox; atual != NULL; atual = atual->prox)
        printf("%s\n", atual->item.nome);
}