#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 30

typedef struct{
    char nome[MAX_CARATTERI];
    float calorie;
} Cibo;

typedef struct nodo{
    Cibo cibo;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);

void insTesta(Lista *pl, Cibo cibo);

void insCoda(Lista *pl, Cibo cibo);

void leggiCibi(Lista *pl, char *nomefile);

void leggiPasto(Lista *pl, char *nomefile);

float calorieTotali(Lista *lista_pasto, Lista *lista_cibi);

void stampaLista(Lista *pl);