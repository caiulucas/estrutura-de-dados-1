#include <stdio.h>
#include "list.h"

int main() {
  int n;
  Item item;
  List list;

  listStart(&list);

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%s ", item.name);
    listInsert(&list, item);
  }

  listPrint(&list);
  // listFree(&list);
  listRemoveFirst(&list, NULL);

  return 0;
}