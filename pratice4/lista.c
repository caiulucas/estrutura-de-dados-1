#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void startList(List *list)
{
  list->head = (Cell *)malloc(sizeof(Cell));
  list->tail = list->head;
  list->head->next = NULL;
}

// Retorna se a lista esta vazia
int isEmpty(List *list)
{
  return list->head == list->tail;
}

// Insere um item no final da lista
int insertEnd(List *list, Item newItem)
{
  list->tail->next = (Cell *)malloc(sizeof(Cell));
  list->tail->next->item = newItem;
  list->tail = list->tail->next;
  list->tail->next = NULL;
  return 1;
}

// Retira o primeiro item da lista
int removeFirst(List *list, Item *item)
{
  if (isEmpty(list))
    return 0;

  Cell *aux = list->head->next;
  *item = aux->item;
  list->head->next = aux->next;
  free(aux);
  return 1;
}

// Imprime os elementos da lista
void print(List *list)
{
  Cell *aux = list->head->next;

  while (aux)
  {
    printf("%s ", aux->item.name);
    aux = aux->next;
  }
}

// Remove cada elemento de uma lista e libera a memória
void clear(List *list)
{
  Cell *actual = list->head;
  Cell *aux = actual;

  while (actual)
  {
    aux = actual->next;
    free(actual);
    actual = aux;
  }
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void append(List *origin, List *new)
{
  origin->tail->next = new->head->next;
  origin->tail = new->tail;
  free(new->head);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void include(List *origin, List *new, char *str)
{
  Cell *aux = origin->head;

  while (aux->next)
  {
    if (strcmp(aux->next->item.name, str) == 0)
    {
      new->tail->next = aux->next;
      aux->next = new->head->next;
      break;
    }
    aux = aux->next;
  }

  free(new->head);
}
