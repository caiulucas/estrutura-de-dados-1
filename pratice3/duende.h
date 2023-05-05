# ifndef duende_h
# define duende_h

typedef struct duende Duende;

// Manter como especificado
void lerQuantidade(int*);

// Manter como especificado
Duende *alocaDuendes(int);

Duende *copiaDuende(Duende*, int);

// Manter como especificado
void desalocaDuendes(Duende**);

// Manter como especificado
void lerDuendes(Duende*, int);

// Manter como especificado
int proximoMaisVelho(Duende*, int);

// Manter como especificado
void escalarDuende(Duende*, int);

// Manter como especificado
void printDuende(Duende*);

# endif