#include "funzioni.h"

void inizializzaListaUtenti(Lista_utenti *pl_utenti){
    *pl_utenti = NULL;
}

void inizializzaListaChiamate(Lista_chiamate *pl_chiamate){
    *pl_chiamate = NULL;
}

void insTestaUtenti(Lista_utenti *pl, Utenti utente){
    Nodo_utenti *aux = malloc(sizeof(Nodo_utenti));
    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }

    aux->utente = utente;
    aux->next = *pl;
    *pl = aux;
}

void insCodaUtenti(Lista_utenti *pl, Utenti utente){
    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTestaUtenti(pl, utente);
}

void insTestaChiamate(Lista_chiamate *pl, Chiamate chiamata){
    {
    Nodo_chiamate *aux = malloc(sizeof(Nodo_chiamate));
    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }

    aux->chiamata = chiamata;
    aux->next = *pl;
    *pl = aux;
}
}

void insCodaChiamate(Lista_chiamate *pl, Chiamate chiamata){
    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTestaChiamate(pl, chiamata);
}

void leggiFileBinario(Lista_utenti *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rb");
    if(pf == NULL){
        printf("Errore apertura file binario.\n");
        exit(3);
    }
    Utenti utente;
    while(fread(&utente, sizeof(Utenti), 1, pf) == 1){
        insCodaUtenti(pl, utente);
    }

    fclose(pf);
}

void leggiFileTesto(Lista_chiamate *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rt");
    if(pf == NULL){
        printf("Errore apertura file di testo.\n");
        exit(4);
    }
    Chiamate chiamata;
    while(fscanf(pf, "%s %d", chiamata.numero_telefono, &chiamata.durata_chiamata) == 2){
        insCodaChiamate(pl, chiamata);
    }

}

void calcoloTariffa(Lista_utenti *pl_utenti, Lista_chiamate *pl_chiamate){

    Nodo_utenti *utente_corrente = *pl_utenti;

    while(utente_corrente != NULL){
        //printf("Sono nel primo while\n");
        Nodo_chiamate *utente_chiamata = *pl_chiamate;
        while(utente_chiamata != NULL){
            //printf("Sono nel secondo while\n");
            if(strcmp(utente_corrente->utente.numero_telefono, utente_chiamata->chiamata.numero_telefono) == 0){
                switch (utente_corrente->utente.piano)
                {
                case 'A':
                    utente_corrente->utente.credito -= (float)((0.15) + (0.08 * (1.0 + (utente_chiamata->chiamata.durata_chiamata / 60))));
                    break;
                case 'B':
                    utente_corrente->utente.credito-= (float)((( 0.12/60) * utente_chiamata->chiamata.durata_chiamata));
                    break;
                
                default:
                    break;
                }
            }

            utente_chiamata = utente_chiamata->next;
        }
        //printf("%s: %.2f\n", utente_corrente->utente.numero_telefono, utente_corrente->utente.credito);
        utente_corrente = utente_corrente->next;
    }
}

void stampaChiamate(Lista_utenti *pl_utenti){
    Nodo_utenti *utente_corrente = *pl_utenti;
    while(utente_corrente != NULL){

        printf("%s: %.2f\n", utente_corrente->utente.numero_telefono, utente_corrente->utente.credito);

        utente_corrente = utente_corrente->next;
    }
}