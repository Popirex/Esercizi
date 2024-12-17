#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 30

typedef struct{
    char nome_cibo[MAX_CARATTERI];
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

void leggiFile(Lista *pl1, Lista *pl2, char *nomefile1, char *noemfile2);

float contaCalorie(Lista *plb, Lista *plt);

