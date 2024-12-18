#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 8

typedef struct {
    char targa[MAX_CARATTERI];
    float durata;
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

void leggiFile(Lista *pl, char *nomefile, Lista *pl_ultime3);

void calcolaAccessi(Lista *pl_disordinata);

void ordinaLista(Lista *pl_disordinata, Lista *pl_ordinata);

void stampa(Lista *pl_ordinata);

void fileUltime(Lista *pl_ultime3);
