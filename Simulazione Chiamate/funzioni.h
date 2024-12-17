#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 11

typedef struct{
    char numero_telefono[MAX_CARATTERI];
    char piano;
    float credito;
} Utenti;

typedef struct nodo_utenti{
    Utenti utente;
    struct nodo_utenti *next;
}Nodo_utenti;

typedef Nodo_utenti *Lista_utenti;

typedef struct{
    char numero_telefono[MAX_CARATTERI];
    int durata_chiamata;
} Chiamate;

typedef struct nodo_chiamate{
    Chiamate chiamata;
    struct nodo_chiamate *next;
}Nodo_chiamate;

typedef Nodo_chiamate *Lista_chiamate;



void inizializzaListaUtenti(Lista_utenti *pl_utenti);

void inizializzaListaChiamate(Lista_chiamate *pl_chiamate);

void insTestaUtenti(Lista_utenti *pl, Utenti utente);

void insCodaUtenti(Lista_utenti *pl, Utenti utente);

void insTestaChiamate(Lista_chiamate *pl, Chiamate chiamata);

void insCodaChiamate(Lista_chiamate *pl, Chiamate chiamata);

void leggiFileBinario(Lista_utenti *pl, char *nomefile);

void leggiFileTesto(Lista_chiamate *pl, char *nomefile);

void calcoloTariffa(Lista_utenti *pl_utenti, Lista_chiamate *pl_chiamate);

void stampaChiamate(Lista_utenti *pl_utenti);