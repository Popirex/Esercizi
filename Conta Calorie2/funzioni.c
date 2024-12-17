#include "funzioni.h"

void inizializzaLista(Lista *pl){
    (*pl) = NULL;
}

void insTesta(Lista *pl, Cibo cibo){
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(1);
    }

    aux->cibo = cibo;
    aux->next = *pl;
    *pl = aux;
}

void insCoda(Lista *pl, Cibo cibo){
    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, cibo);
}

void leggiFile(Lista *pl1, Lista *pl2, char *nomefile1, char *nomefile2){
    FILE *pfb = fopen(nomefile1, "rb");
    if(pfb == NULL){
        printf("Errore apertura file binario.\n");
        exit(2);
    }
    Cibo cibo;
    while(fread(&cibo, sizeof(Cibo), 1, pfb) == 1){
        insCoda(pl1, cibo);
    }
    fclose(pfb);
    printf("\n");


    FILE *pft = fopen(nomefile2, "rt");
    if(pfb == NULL){
        printf("Errore apertura file testo.\n");
        exit(3);
    }
    Cibo pasto;
    while(fscanf(pft, "%s %f", pasto.nome_cibo, &pasto.calorie) == 2){
        insCoda(pl2, pasto);
    }
    fclose(pft);

}

float contaCalorie(Lista *plb, Lista *plt){
    Nodo *pasto_corrente = *plt;

    float calorie_totali = 0.0;
    
    while(pasto_corrente != NULL){
        int trovato = 0;
        Nodo *cibo_corrente = *plb;
        while(cibo_corrente != NULL){

            if(strcmp(cibo_corrente->cibo.nome_cibo, pasto_corrente->cibo.nome_cibo) == 0){
                calorie_totali += pasto_corrente->cibo.calorie * (cibo_corrente->cibo.calorie / 100);
                trovato++;
            }

            cibo_corrente = cibo_corrente->next;
        }


        if(trovato == 0){
            printf("%s non e' presente nella lista, termino esecuzione programma.\n", pasto_corrente->cibo.nome_cibo);
            exit(6);
        }

        pasto_corrente = pasto_corrente->next;
    }

    return calorie_totali;
}