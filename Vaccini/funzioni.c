#include "funzioni.h"

void inizializzaLista(Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Cane cane){
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }
    aux->cane = cane;
    aux->next = *pl;
    *pl = aux;
}

void insCoda(Lista *pl, Cane cane){
    while(*pl!=NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, cane);
}

void leggiFile(Lista *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rb");
    if(pf == NULL){
        printf("Errore apertura file.\n");
        exit(3);
    }
    Cane cane;
    while(fread(&cane, sizeof(Cane)-12, 1, pf) == 1){
        insCoda(pl, cane);
    }
    fclose(pf);
}

void ordinaLista(Lista *plg, Lista *plo){
    Nodo *corrente = *plg;

    Nodo *corrente2 = *plg;

    while(corrente != NULL){
        Nodo *nuovo = *plg;
        while(nuovo !=NULL){
            if(corrente->cane.chip == nuovo->cane.chip){
                switch (nuovo->cane.vaccino){
                    case 'C':
                        corrente->cane.c = 1;
                        break;
                    case 'E':
                        corrente->cane.e = 1;
                        break;
                    case 'P':
                        corrente->cane.p = 1;
                        break;
                
                    default:
                        break;
                }
            }
            nuovo = nuovo->next;
        }
        printf("%d: %d %d %d\n", corrente->cane.chip, corrente->cane.c, corrente->cane.e, corrente->cane.p);
        corrente = corrente->next;
    }

    while(corrente2 != NULL){
        int trovato = 0;
        Nodo *nuovo = *plo;
        while(nuovo !=NULL){
            if(corrente2->cane.chip == nuovo->cane.chip){
                trovato++;
            }
            nuovo = nuovo->next;
        }

        if(!trovato){   
        insCoda(plo, corrente2->cane);
        }

        printf("%d: %d %d %d\n", corrente2->cane.chip, corrente2->cane.c, corrente2->cane.e, corrente2->cane.p);
        corrente2 = corrente2->next;
    }
}

void stampa(Lista *pl){
    while(*pl != NULL){
        printf("%d: ", (*pl)->cane.chip);
        if((*pl)->cane.c == 0){
            printf("Cimurro ");
        }
        if((*pl)->cane.e == 0){
            printf("Epatite ");
        }
        if((*pl)->cane.p == 0){
            printf("Parvovirosi ");
        }
        printf("\n");
        (*pl) = (*pl)->next;
    }
}