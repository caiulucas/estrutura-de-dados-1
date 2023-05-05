#ifndef D_TIME_H
#define D_TIME_H

#include "duende.h"

typedef struct time Time;

// Manter como especificado
Time *alocaTimes(int);

// Manter como especificado
void desalocaTimes(Time**, int);

// Manter como especificado
void escalarTimes(Duende*, Time*, int);

// Manter como especificado
void printTimes(Time*, int);

#endif // !D_TIME_H