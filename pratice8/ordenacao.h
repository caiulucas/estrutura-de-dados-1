# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
  int id;
  int vitorias;
  int derrotas;
  int pontosSofridos;
  int saldoPontos;
} Time;

// Manter como especificado
void heapSort(Time *vetor, int n);

void mergeSort(Time *vetor, int left, int right);

void quickSort(Time *vetor, int left, int right);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

# endif
