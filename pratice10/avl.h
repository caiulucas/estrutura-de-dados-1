# ifndef avl_h
# define avl_h

#include <stdbool.h>

typedef char Chave[200];

typedef struct {
  Chave chave;
} Item;

typedef struct no {
  Item item;
  int cont;
  struct no* pEsq;
  struct no* pDir;
} No;

typedef No* AVL;

typedef enum {
  MENOR=1,
  MAIOR,
  IGUAL
} RELACAO;

/* Inicia a árvore */
void inicia(No **);

/* Libera a memória */
void libera(No **);

/* Insere um nó na árvore */
bool insere(No **, Item);

/* Cria um nó e retorna o endereço alocado */
No* criaNo(Item);

/* Retorna se o primeiro item é maior, menor ou igual ao segundo */
RELACAO compara(const Item, const Item);

/* Função para calcular o fator de balanceamento */
int FB(No*);

/* Altura de um nó */
int altura(No*);

/* Realiza o caminhamento adequado na arvore */
void caminhamento(No*);

/* Realiza a rotação de um nó à esquerda */
void RSE(No**);

/* Realiza a rotação de um nó à direita */
void RSD(No**);

/* Balancea à esquerda */
int BalancaEsquerda(No**);

/* Balancea à direita */
int BalancaDireita(No**);

/* Balancea um nó */
int Balanceamento(No**);

# endif
