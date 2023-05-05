#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void listStart(List *list)
{
  list->head = (Cell *)malloc(sizeof(Cell));
  list->tail = list->head;
}

bool listIsEmpty(List *list)
{
  return list->head == list->tail;
}

void listInsert(List *list, Item item)
{ 
  Cell *newCell = (Cell *)malloc(sizeof(Cell));
  newCell->item = item;
  newCell->prev = list->tail;
  newCell->next = NULL;

  list->tail->next = newCell;
  list->tail = list->tail->next;
}

bool listRemoveFirst(List *list, Item *item)
{
  if (listIsEmpty(list))
    return false;

  Cell *aux = list->head->next;
  *item = aux->item;
  list->head->next = aux->next;
  free(aux);
  return true;
}

void listPrint(List *list)
{
  for (Cell *i = list->head->next; i != NULL; i = i->next)
  {
    printf("%s \n", i->item.name);
  }
}

void listFree(List *list)
{
  while (listRemoveFirst(list, NULL))
    ;

  free(list);
}