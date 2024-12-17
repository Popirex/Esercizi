#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 8

typedef struct {
    char targa[MAX_CARATTERI];
    float sosta;
    int accessi;
} Veicoli;

typedef struct nodo{
    Veicoli veicolo;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);

void insTesta(Lista *pl, Veicoli veicolo);

void insCoda(Lista *pl, Veicoli veicolo);

void leggiFile(Lista *pl,char *nomefile);

void verificaAccessi(Lista *pl, Lista *plo);

void stampa(Lista *pl);