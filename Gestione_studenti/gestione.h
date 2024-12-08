#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTI 150

typedef struct
{
    char nome[50];
    int eta;
    float media_voti;
} Studente;

void aggiungiStudente(Studente *elenco, int *num_studenti, char *nome, int eta, float media_voti);

void stampaStudenti(Studente *elenco, int num_studenti);

float mediaComplessiva(Studente *elenco, int num_studenti);

void esportaStudenti(Studente *elenco, int num_studenti, const char* nome_file);

void sovrascriviLista(const char* nome_file);