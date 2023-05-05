# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    char nome[21];
} Aluno;

// Manter como especificado
void ordena(Aluno*, int);

/* Manter como especificado
 * Retorna:
 *      -1 se o primeiro TItem for menor que o segundo
 *       0 se ambos forem iguais
 *       1 se o primeiro TItem for maior que o segundo
 */
int compare(const char*, const char*);

/* Manter como especificado
 * Imprime a resposta esperada pelo exercicio
 */
void imprimeResposta(Aluno*, int, int);

/* Manter como especificado
 * Aloca um vetor de alunos
 */
Aluno* alocaAlunos(int);

/* Manter como especificado
 * Libera um vetor de alunos
 */
void liberaAlunos(Aluno**);

/* Manter como especificado
 * Le os dados dos alunos
 */
void leAlunos(Aluno*, int);

/* Manter como especificado
 * Le as quantidades de alunos e o valor k
 */
void leQuantidades(int*, int*);

# endif
