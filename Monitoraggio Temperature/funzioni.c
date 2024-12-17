#include "funzioni.h"

void inizializzaLista(Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Temperature temperatura){
    Nodo *aux = malloc(sizeof(Nodo));

    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }

    aux->temperatura = temperatura;
    aux->next = *pl;
    *pl = aux;

}

void insCoda(Lista *pl, Temperature temperatura){
    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, temperatura);
}

void leggiFile(Lista *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rb");

    if(pf == NULL){
        printf("Errore apertura file binario.\n");
        exit(3);
    }
    Temperature temperatura;
    while(fread(&temperatura, sizeof(Temperature), 1, pf) == 1){
        printf("%s: %f\n", temperatura.citta, temperatura.gradi);
        if(strcmp(temperatura.citta, "Roma") == 0){
            printf("conta come uguale\n");
        }
        insCoda(pl, temperatura);
    }
    fclose(pf);
}