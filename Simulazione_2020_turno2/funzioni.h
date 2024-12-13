#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int chip;
    char vc;
    int c;
    int e;
    int p;
} Cane;

typedef struct nodo{
    Cane cane;
    int dl;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl, int *dl);

void insTesta(Lista *pl, Cane cane);

void leggiFile(char *argv, Lista *pl, int *dl);

void verificaVaccino(Lista *pl);

void stampaTabella(Lista *pl); //stampa il numero del chip e le tipologie di vaccini non ancora fatti

void filtra(Lista l1, Lista *pl2, int dl);

void stampa(Lista l);


 