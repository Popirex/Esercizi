#include "accessoUtenti.h"



void insTesta(Lista *pl, Utente utente){
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL ){
        printf("Errore allocazione memoria\n");
        exit(200);
    }

    aux->utente = utente;
    aux->next = (*pl);
    (*pl) = aux;
}

void insCoda(Lista *pl, Utente utente){
    while((*pl) != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, utente);
}

void leggiBin(Lista *pl, char *nomefile1, char *nomefile2){
    /*deve leggere il file binario che contiene il codice fiscale degli iscritti in palestra
    dopodiche legge dal file di testo il codice fiscale e l'attivita che puo essere 1 o 2 o 3, 
    verificare l'attivita per ogni codice fiscale e sottrarla a a1 a2 a3, in modo da avere nella lista di utenti i codici fiscali ordianti
    e gli accessi ancora disponibili per la settimana*/
    Utente utente;
    Utente utente_testo;

    FILE *pfb = fopen(nomefile1, "rb");
    FILE *pft = fopen(nomefile2, "rt");

    if(pfb == NULL){
        printf("Errore apertura file binario\n");
        exit(100);
    }

    if(pft == NULL){
        printf("Errore apertura file testo\n");
        exit(200);
    }


    while(fread(&(utente).codice_fiscale, sizeof(utente.codice_fiscale), 1, pfb) ==1 ){

        utente.a1 = 4;
        utente.a2 = 4;
        utente.a3 = 4;

        rewind(pft);
        while(fscanf(pft, "%s%d",utente_testo.codice_fiscale, &utente_testo.attivita) == 2){
            if(strcmp(utente.codice_fiscale, utente_testo.codice_fiscale) == 0){
                switch (utente_testo.attivita)
                {
                case 1:
                    utente.a1--;
                    break;
                case 2:
                    utente.a2--;
                    break;
                case 3:
                    utente.a3--;
                    break;
                default:
                    break;
                }
            }
        }
        insCoda(pl, utente);
    }
    fclose(pft);
    fclose(pfb);
}

void stampa(Lista *pl){
    Nodo *corrente;
    corrente = *pl;
    while(corrente!=NULL){
        printf("%s: %d %d %d \n", corrente->utente.codice_fiscale, corrente->utente.a1, corrente->utente.a2, corrente->utente.a3 );
        corrente = corrente->next;
    }
}