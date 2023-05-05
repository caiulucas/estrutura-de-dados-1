#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Manter como especificado */
void inicia(No **ppRaiz)
{
  *ppRaiz = NULL;
}

/* Manter como especificado */
void libera(No **ppRaiz)
{
  if (*ppRaiz != NULL)
  {
    libera(&(*ppRaiz)->pEsq);
    libera(&(*ppRaiz)->pDir);
    free(*ppRaiz);
    *ppRaiz = NULL;
  }
}

/* Manter como especificado */
bool insere(No **ppRaiz, Item x)
{
  if (*ppRaiz == NULL)
  {
    *ppRaiz = criaNo(x);
    return true;
  }
  else if (compara((*ppRaiz)->item, x) == MAIOR)
  {
    if (insere(&(*ppRaiz)->pEsq, x))
    {
      if (Balanceamento(ppRaiz))
        return false;

      else
        return true;
    }
  }
  else if (compara((*ppRaiz)->item, x) == MENOR)
  {
    if (insere(&(*ppRaiz)->pDir, x))
    {
      if (Balanceamento(ppRaiz))
        return false;
      else
        return true;
    }
    else
      return false;
  }
  else
    (*ppRaiz)->cont++;
  return false;
}

/* Manter como especificado */
No *criaNo(Item x)
{
  No *pAux = (No *)malloc(sizeof(No));
  pAux->cont = 1;
  pAux->item = x;
  pAux->pEsq = NULL;
  pAux->pDir = NULL;
  return pAux;
}

/* Manter como especificado */
void caminhamento(No *pNo)
{
  if (pNo == NULL)
    return;
  caminhamento(pNo->pEsq);
  printf("%s %d\n", pNo->item.chave, pNo->cont);
  caminhamento(pNo->pDir);
}

/* Manter como especificado */
RELACAO compara(const Item item1, const Item item2)
{
  int response = strcmp(item1.chave, item2.chave);
  if (response < 0)
    return MENOR;
  else if (response > 0)
    return MAIOR;
  return IGUAL;
}

/* Manter como especificado */
int FB(No *pRaiz)
{
  if (pRaiz == NULL)
    return 0;

  return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

/* Manter como especificado */
int altura(No *pRaiz)
{
  if (pRaiz == NULL)
    return 0;

  int indiceEsq = altura(pRaiz->pEsq);
  int indiceDir = altura(pRaiz->pDir);

  if (indiceEsq > indiceDir)
    return indiceEsq + 1;

  return indiceDir + 1;
}

/* Manter como especificado */
void RSE(No **ppRaiz)
{
  No *pAux = (*ppRaiz)->pDir;
  (*ppRaiz)->pDir = pAux->pEsq;
  pAux->pEsq = (*ppRaiz);
  (*ppRaiz) = pAux;
}

/* Manter como especificado */
void RSD(No **ppRaiz)
{
  No *pAux = (*ppRaiz)->pEsq;
  (*ppRaiz)->pEsq = pAux->pDir;
  pAux->pDir = (*ppRaiz);
  (*ppRaiz) = pAux;
}

/* Manter como especificado */
int BalancaEsquerda(No **ppRaiz)
{
  int fbe = FB((*ppRaiz)->pEsq);
  if (fbe >= 0)
  {
    RSD(ppRaiz);
    return 1;
  }

  RSE(&((*ppRaiz)->pEsq));
  RSD(ppRaiz);
  return 1;
}

/* Manter como especificado */
int BalancaDireita(No **ppRaiz)
{
  int fbd = FB((*ppRaiz)->pDir);
  if (fbd < 0)
  {
    RSE(ppRaiz);
    return 1;
  }

  RSD(&((*ppRaiz)->pDir));
  RSE(ppRaiz);
  return 1;
}

/* Manter como especificado */
int Balanceamento(No **ppRaiz)
{
  int fb = FB(*ppRaiz);
  if (fb > 1)
    return BalancaEsquerda(ppRaiz);
  else if (fb < -1)
    return BalancaDireita(ppRaiz);
  else
    return 0;
}
