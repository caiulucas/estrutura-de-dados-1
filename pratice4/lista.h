# ifndef lista_h
# define lista_h
#define MAX_SIZE 20

typedef struct {
  char name[MAX_SIZE];
} Item;

typedef struct cell {
  Item item;
  struct cell *next;
} Cell;

typedef struct {
  Cell *head;
  Cell *tail;
} List;

//Inicializa a lista
void startList(List *list);
//Retorna se a lista esta vazia
int isEmpty(List *list);
// Insere um item no final da lista
int insertEnd(List *list, Item newItem);
// Retira o primeiro item da lista
int removeFirst(List *list, Item *item);
// Imprime os elementos da lista
void print(List *list);
// Remove cada elemento de uma lista e libera a memória
void clear(List *list);
// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void append(List *origin, List *new);
// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void include(List *origin, List *new, char *str);
# endif
