#include <stdbool.h>

typedef struct
{
  char name[30];
} Item;

typedef struct cell
{
  Item item;
  struct cell *next;
  struct cell *prev;
} Cell;

typedef struct
{
  Cell *head;
  Cell *tail;
} List;

void listStart(List *list);

bool listIsEmpty(List *list);

void listInsert(List *list, Item item);

bool listRemoveFirst(List *list, Item *item);

void listPrint(List *list);

void listFree(List *list);