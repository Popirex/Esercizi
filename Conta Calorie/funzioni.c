#include "funzioni.h"

void inizializzaLista(Lista *pl){
    (*pl) = NULL;
}

void insTesta(Lista *pl, Cibo cibo){
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(100);
    }

    aux->cibo = cibo;
    aux->next = (*pl);
    (*pl) = aux;
}

void insCoda(Lista *pl, Cibo cibo){
    while((*pl) != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, cibo);
}

void leggiCibi(Lista *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rb");
    if(pf == NULL){
        printf("Errore apertura file binario\n");
        exit(200);
    }
    Cibo cibo;
    while(fread(&cibo, sizeof(Cibo), 1, pf) == 1){
        insCoda(pl, cibo);
    }
    fclose(pf);
}

void leggiPasto(Lista *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rt");
    if(pf == NULL){
        printf("Apertura file di testo non riuscita\n");
        exit(1);
    }

    Cibo cibo;
    while(fscanf(pf, "%s %f", cibo.nome, &cibo.calorie) == 2){
        insCoda(pl,cibo);
    }
    fclose(pf);
}

float calorieTotali(Lista *lista_pasto, Lista *lista_cibi){
    float calorie_totali = 0.0;

    Nodo *pasto_corrente = *lista_pasto;
    while(pasto_corrente != NULL){
        Nodo *cibo_corrente = *lista_cibi;
        int elementi_lista = 0;
        while(cibo_corrente != NULL){


            if(strcmp(pasto_corrente->cibo.nome, cibo_corrente->cibo.nome) == 0){
                calorie_totali += (pasto_corrente->cibo.calorie * (cibo_corrente->cibo.calorie / 100));
            }
            else{
                elementi_lista++;
            }

            cibo_corrente = cibo_corrente->next;
        }
        if(elementi_lista > 108){
            printf("%s non e' presente nella lista, termino esecuzione programma\n", pasto_corrente->cibo.nome);
            exit(3);
        }
        pasto_corrente = pasto_corrente->next;
    }

    return calorie_totali;
}
