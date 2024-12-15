#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARATTERI 17

/*• prendere come argomenti della linea di comando i nomi, rispettivamente, di un file
binario e di un file di testo dei formati sopra indicati;

• creare una lista collegata contenente un elemento per ogni utente (quindi, se il file
binario è quello allegato, la lista dovrà avere 4 elementi). Si suggerisce che l’elemen-
to della lista sia composto dal codice fiscale e da tre contatori degli accessi residui,
uno per ogni attività, inizializzati a 4;

• per ogni tentativo di ingresso di un utente a un’attività, verificare che l’utente non
abbia esaurito i suoi ingressi per quell’attività; in caso che gli ingressi siano esauriti, 
stampare un messaggio di accesso negato, altrimenti decrementare il contato-
re degli accessi dell’utente per l’attività. Ad esempio, a seguito del primo tentati-
vo di ingresso contenuto nel file ingressi.txt, dovrebbe essere decrementato il
contatore relativo all’attività 2 dell’utente di codice fiscale LPNVRR74D54A850W*/

typedef struct {
    char codice_fiscale[MAX_CARATTERI];
    int attivita;
    int a1;
    int a2;
    int a3;
} Utente;


typedef struct nodo{
    Utente utente;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;


void inizializzaBinaria(Lista *pl);

void insTesta(Lista *pl, Utente utente);

void insCoda(Lista *pl, Utente utente);

void leggiBin(Lista *pl, char *nomefile1, char *nomefile2);

void stampa(Lista *pl);