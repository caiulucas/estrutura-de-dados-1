# ifndef duende_h
# define duende_h

typedef enum { NAO=0, SIM } ESCALADO;

typedef struct {
  char nome[20];
  int idade;
  ESCALADO escalado;
} Duende;

typedef struct {
  char nomeLider[20];
  char nomeConfeiteiro[20];
  char nomeEntregador[20];
  char nomeEmbrulhador[20];
  int idadeLider;
  int idadeConfeiteiro;
  int idadeEntregador;
  int idadeEmbrulhador;
} Time;


// Manter como especificado
void lerQuantidade(int*);

// Manter como especificado
Duende *alocaDuendes(int);

// Manter como especificado
Time *alocaTimes(int);

// Manter como especificado
void desalocaDuendes(Duende**);

// Manter como especificado
void desalocaTimes(Time**);

// Manter como especificado
void lerDuendes(Duende*, int);

// Manter como especificado
void escalarTimes(Duende*, Time*, int);

// Manter como especificado
int proximoMaisVelho(Duende*, int);

// Manter como especificado
void printTimes(Time*, int);

# endif