#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 8

typedef struct{

    char targa[MAX_CARATTERI];
    float sosta;
    int numero_accessi;

} Veicolo;


typedef struct nodo{
    Veicolo veicolo;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;

void leggiFile(Lista *pl, char *argv);

void inizializzaListe(Lista *pl,Lista *pl2);

void insTesta(Lista *pl, Veicolo veicolo);

void insCoda(Lista *pl, Veicolo veicolo);

void stampa(Lista *pl);

void ordinaLista(Lista *pl1, Lista *pl2);

float calcolaPrezzo(Nodo *pl);