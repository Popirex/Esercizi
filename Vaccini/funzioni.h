#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int chip;
    char vaccino;
    int c;
    int e;
    int p;

} Cane;

typedef struct nodo{
    Cane cane;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);

void insTesta(Lista *pl, Cane cane);

void insCoda(Lista *pl, Cane cane);

void leggiFile(Lista *pl, char *nomefile);

void ordinaLista(Lista *plg, Lista *plo);

void stampa(Lista *pl);