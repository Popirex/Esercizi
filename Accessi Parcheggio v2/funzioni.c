#include "funzioni.h"

void inizializzaLista(Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Veicoli veicolo){
    Nodo *aux = malloc(sizeof(Nodo));

    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }

    aux->veicolo = veicolo;
    aux->next = *pl;
    *pl = aux;
}

void insCoda(Lista *pl, Veicoli veicolo){
    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, veicolo);
}

void leggiFile(Lista *pl, char *nomefile){
    FILE *pfb = fopen(nomefile, "rb");

    if(pfb == NULL){
        printf("Errore apertura file.\n");
        exit(3);
    }
    Veicoli veicolo;
    while(fread(&veicolo, sizeof(Veicoli)-4, 1, pfb) == 1){
        veicolo.accessi = 1;
        insCoda(pl, veicolo);
    }
}
void verificaAccessi(Lista *pl, Lista *plo){
    Nodo *veicolo_corrente = *pl;

    while(veicolo_corrente != NULL){
        Nodo *veicolo_istantaneo = *plo;
        int trovato = 0;
        while(veicolo_istantaneo != NULL){
            if(strcmp(veicolo_corrente->veicolo.targa, veicolo_istantaneo->veicolo.targa) == 0){
                veicolo_istantaneo->veicolo.accessi++;
                trovato = 1;
                break;
            }

            veicolo_istantaneo = veicolo_istantaneo->next;
        }

        if(!trovato){
            insCoda(plo, veicolo_corrente->veicolo);
        }

        veicolo_corrente = veicolo_corrente->next;
    }

}

void stampa(Lista *pl){
    while(*pl != NULL){
        if((*pl)->veicolo.accessi <= 5){
            printf("%s: %.2f\n", (*pl)->veicolo.targa, (*pl)->veicolo.accessi* 2.0);
        }
        else if((*pl)->veicolo.accessi >5 && (*pl)->veicolo.accessi <=10){
            printf("%s: %.2f\n", (*pl)->veicolo.targa, (*pl)->veicolo.accessi* 1.9);
        }
        else if((*pl)->veicolo.accessi > 10){
            printf("%s: %.2f\n", (*pl)->veicolo.targa, (*pl)->veicolo.accessi* 1.8);
        }

        *pl = (*pl)->next;
    }
}