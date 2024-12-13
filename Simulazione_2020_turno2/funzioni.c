#include "funzioni.h"


void inizializzaLista(Lista *pl, int *dl)
{
    pl = NULL;
    (*dl) = 0;
}

void insTesta(Lista *pl, Cane cane)
{
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("Allocazione non riuscita\n");
        exit(1);
    }
    aux->cane.chip = cane.chip;
    aux->cane.vc = cane.vc;
    switch (cane.vc)
    {
    case 'C':
        aux->cane.c = 1;
        break;
    case 'E':
        aux->cane.e = 1;
        break;
    case 'P':
        aux->cane.p = 1;
    break;
    default:
        break;
    }
    aux->next = *pl;
    *pl = aux;


    //printf("Chip: %d   Vaccino: C: %d E: %d P: %d \n", (*pl)->cane.chip, (*pl)->cane.c, (*pl)->cane.e, (*pl)->cane.p);
}

void leggiFile(char *argv, Lista *pl, int *dl)
{
    Cane cane;

    FILE *pfi = fopen(argv, "rb");
    if(pfi == NULL){
        printf("Errore apertura file di input.\n");
        exit(2);
    }

    while(fread(&cane, sizeof(Cane)-12, 1, pfi) == 1) //-12 perche nella typef specifico varie variabili con una memoria specifica ma ora il dato che debo vedere io è solo int + char;
    {
        insTesta(pl, cane);
        (*dl)++;
    }
    fclose(pfi);
}

void filtra(Lista l1, Lista *pl2, int dl) {
    for (int i = 0; i < dl; i++) {
        Nodo *corrente = *pl2;
        int trovato = 0;

        while (corrente) {
            //AGGIORNO I FLAG SE IL CHIP È GIA PRESENTE
            if (corrente->cane.chip == l1->cane.chip) {
                trovato = 1;
                if (l1->cane.c == 1) corrente->cane.c = 1;
                if (l1->cane.e == 1) corrente->cane.e = 1;
                if (l1->cane.p == 1) corrente->cane.p = 1;
                break;
            }
            corrente = corrente->next;
        }
        //SE IL CHIP NON È IN PL2, CREO UN NUOVO NODO E GLI ASSEGNO I VALORI
        if (!trovato) {
            Nodo *aux = malloc(sizeof(Nodo));
            if (!aux) {
                printf("Errore di allocazione memoria\n");
                exit(1);
            }
            aux->cane.chip = l1->cane.chip;
            aux->cane.c = l1->cane.c;
            aux->cane.e = l1->cane.e;
            aux->cane.p = l1->cane.p;
            aux->next = *pl2;
            *pl2 = aux;
        }

        //PASSO AL PROSSIMO NODO
        if (l1) {
            l1 = l1->next;
        }
    }
}

void stampa(Lista l)
{
    while(l){
        printf("CHIP: %d : ", l->cane.chip);
        if(l->cane.c == 0) printf("cimurro ");
        if(l->cane.e == 0) printf("epatite ");
        if(l->cane.p == 0) printf("parovovirosi ");
        if(l->cane.c == 0 && l->cane.e == 0 && l->cane.p == 0) printf("Nessun vaccino disponibile.");
        printf("\n");
        l = l->next;
    }
}