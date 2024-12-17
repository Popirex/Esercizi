#include "funzioni.h"

void inizializzaListe(Lista *pl, Lista *pl2)
{
    (*pl) = NULL;
    (*pl2) = NULL;
}

void leggiFile(Lista *pl, char *argv){
    Veicolo veicolo;
    FILE *pf = fopen(argv, "rb");

    if(pf == NULL){
        printf("Errore apertura file input;\n");
        exit(1);
    }
    while(fread(&veicolo, (sizeof(veicolo.targa)+sizeof(veicolo.sosta)), 1, pf) == 1){
        veicolo.numero_accessi = 1;
        insCoda(pl, veicolo);
    }
    fclose(pf);
}


void insTesta(Lista *pl, Veicolo veicolo){
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("Allocazione non riuscita\n");
        exit(100);
    }
    aux->veicolo = veicolo;
    aux->next = (*pl);
    (*pl) = aux;
}

void insCoda(Lista *pl, Veicolo veicolo){
    while((*pl) != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, veicolo);
}

void ordinaLista(Lista *pl1, Lista *pl2){
    Nodo *corrente = *pl1; //per scorrere tra i nodi della prima lista

    while(corrente!=NULL){
        Nodo *cerca = *pl2;
        int trovato = 0;

        while(cerca!= NULL){
            if(strcmp(cerca->veicolo.targa, corrente->veicolo.targa) == 0){
                //se la targa esiste gia nella lista due aggiungo solo il numero di accessi
                cerca->veicolo.numero_accessi++;
                trovato = 1;
                break;
            }
            cerca = cerca->next;
        }
        //se non trovo la targa del veicolo, la aggiungo alla seconda lista
        if(!trovato){
            insCoda(pl2, corrente->veicolo);
        }
        corrente = corrente->next;
    }
}

float calcolaPrezzo(Nodo *pl){
    if(pl->veicolo.numero_accessi <= 5){
        return 2.0 * pl->veicolo.numero_accessi;
    }
    else if(pl->veicolo.numero_accessi > 5 && pl->veicolo.numero_accessi <= 10){
        return 1.9*pl->veicolo.numero_accessi;
    }
    else if(pl->veicolo.numero_accessi > 10){
        return 1.8 * pl->veicolo.numero_accessi;
    }
}


void stampa(Lista *pl)
{
    Nodo *corrente = NULL;
    corrente = *pl;
    while(corrente != NULL){
        printf("%s: %.2f\n", corrente->veicolo.targa, calcolaPrezzo(corrente));
        corrente = corrente->next;
    }
}
