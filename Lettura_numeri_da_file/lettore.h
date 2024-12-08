#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // mi permette di avere INT_MIN e INT_MAX per determinare minimo e massimo
#define MAX_NUMERI 100

int leggiNumeriFile( const char *nomefile, int *numeri);

int somma(int *numeri, int conteggio);

int massimo(int *numeri, int conteggio);

int minimo(int *numeri, int conteggio);

void stampaOutput(const char *fileoutput,int somma ,int massimo, int minimo);