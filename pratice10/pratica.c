#include "avl.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// O MAIN NAO PRECISA SER ALTERADO
int main ()
{
    AVL avl;
    Item aux;
    int comprimento, i;
    char string[10000];
    char *charPtr;

    // Inicializar a arvore
    inicia(&avl);

    // enquanto houver string sendo lida
    while(scanf("%s", string) == 1)
    {
        // dispensa o \n
        getchar();
        // determina o numero de caracteres da string
        comprimento = strlen(string);
        // se tiver tamanho zero, pula
        if(!comprimento)
            continue;

        // para cada um dos caracteres da string
        for (i = 0; i < comprimento; ++i)
        {
            // transforma em caracteres minúsculos
            string[i] = tolower(string[i]);
            // se o caractere não for uma letra minuscula
            if(string[i] < 'a' || string[i] > 'z')
                // atribui o codigo de espaco em branco
                string[i] = 32;
        }
        // a funcao strk divide uma string em substrings chamadas tokens
        charPtr = strtok(string, " ");

        // enquanto o ponteiro for valido
        while(charPtr != NULL)
        {
            // se o token apontado pelo ponteiro tiver comprimento maior que zero
            if(strlen(charPtr) != 0){
                // copiar o token para o TItem aux
                strcpy(aux.chave, charPtr);
                // inserir aux na arvore
                insere(&avl, aux);
            }
            // pega o proximo token
            charPtr = strtok(NULL, " ");
        }
    }
    printf("%d\n", altura(avl));

    // realizar o caminhamento adequado na arvore de forma a imprimir as palavras em ordem alfabetica
    caminhamento(avl);

    // Liberar memoria
    libera(&avl);

    return 0;
}
