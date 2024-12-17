#include "funzioni.h"

void inizializzaLista(Lista *pl){
    *pl = NULL;
}

void insTesta(Lista *pl, Prodotti prodotto){
    Nodo *aux = malloc(sizeof(Nodo));

    if(aux == NULL){
        printf("Errore allocazione memoria.\n");
        exit(2);
    }

    aux->prodotto = prodotto;
    aux->next = *pl;
    *pl = aux;
}

void insCoda(Lista *pl, Prodotti prodotto){

    while(*pl != NULL){
        pl = &(*pl)->next;
    }
    insTesta(pl, prodotto);
}

void leggiFile(Lista *pl, char *nomefile){
    FILE *pf = fopen(nomefile, "rb");

    if(pf == NULL){
        printf("Errore aprertura file binario.\n");
        exit(3);
    }
    Prodotti prodotto;
    while(fread(&prodotto, sizeof(Prodotti), 1, pf) == 1){
        insCoda(pl, prodotto);
    }
    fclose(pf);

}

void verificaProdotti(Lista l, char *nomefile){
    Nodo *prodotto_corrente = l;

    FILE *pf = fopen(nomefile, "rt");

    if(pf == NULL){
        printf("Errore apertura file di testo.\n");
        exit(4);
    }
    Prodotti prodotto;
    while(fscanf(pf, "%s %d", prodotto.nome, &prodotto.quantita) == 2){
        int trovato = 0;
        while(prodotto_corrente != NULL){
            if(strcmp(prodotto_corrente->prodotto.nome, prodotto.nome) == 0 && prodotto.quantita <= prodotto_corrente->prodotto.quantita){
                printf("%s disponibile (%d/%d)\n", prodotto_corrente->prodotto.nome, prodotto_corrente->prodotto.quantita - prodotto.quantita, prodotto_corrente->prodotto.quantita);
                trovato++;
                }
            else if(prodotto.quantita > prodotto_corrente->prodotto.quantita){
                printf("La quantita richiesta di %s non è disponibile, sono disponibili in magazzino %d pezzi\n", prodotto_corrente->prodotto.nome ,prodotto_corrente->prodotto.quantita);
                trovato++;
            }

            prodotto_corrente = prodotto_corrente->next;
            if(trovato) break;
            }

            if(trovato < 1){
                printf("%s non è in magazzino\n", prodotto.nome);
                exit(7);
            }
        }
    }
