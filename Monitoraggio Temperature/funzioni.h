#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 50

typedef struct{
    char citta[MAX_CARATTERI];
    float gradi;
} Temperature;

typedef struct nodo{
    Temperature temperatura;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;

void inizializzaLista(Lista *pl);

void insTesta(Lista *pl, Temperature temperatura);

void insCoda(Lista *pl, Temperature temperatura);

void leggiFile(Lista *pl, char *nomefile);