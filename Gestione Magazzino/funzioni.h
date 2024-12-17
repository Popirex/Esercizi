#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 31

typedef struct{
    char nome[MAX_CARATTERI];
    int quantita;

} Prodotti;

typedef struct nodo{
    Prodotti prodotto;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);

void insTesta(Lista *pl, Prodotti prodotto);

void insCoda(Lista *pl, Prodotti prodotto);

void leggiFile(Lista *pl, char *nomefile);

void verificaProdotti(Lista l, char *nomefile);

