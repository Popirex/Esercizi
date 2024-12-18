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

void leggiFile(Lista *pl, char *nomefile, Lista *pl_ultime3){

    FILE *pf = fopen(nomefile, "rb");
    if(pf == NULL){
        printf("Errore apertura file binario.\n");
        exit(3);
    }
    int contatore = 0;
    Veicoli veicolo;
    while(fread(&veicolo, sizeof(Veicoli)- 4, 1, pf) == 1){
        contatore++;
        insCoda(pl, veicolo);
        if(contatore > 27){
            insTesta(pl_ultime3, veicolo);
        }
    }
    fclose(pf);
}

void calcolaAccessi(Lista *pl_disordinata){
    Nodo *corrente = *pl_disordinata;
    while(corrente!=NULL){
        Nodo *nuovo = *pl_disordinata;
        while(nuovo != NULL){

            if(strcmp(corrente->veicolo.targa, nuovo->veicolo.targa) == 0){
                corrente->veicolo.accessi++;
            }

            nuovo = nuovo->next;
        }
        corrente = corrente->next;
    }

}

void ordinaLista(Lista *pl_disordinata, Lista *pl_ordinata){
    Nodo *corrente = *pl_disordinata;
    while(corrente!=NULL){
        int trovato = 0;
        Nodo *nuovo = *pl_ordinata;
        while(nuovo != NULL){
            if(strcmp(corrente->veicolo.targa, nuovo->veicolo.targa)==0){
                trovato++;
            }

            nuovo = nuovo->next;
        }


        if(!trovato){
            insCoda(pl_ordinata, corrente->veicolo);
        }
        corrente = corrente->next;
    }
}

void stampa(Lista *pl){
    Nodo *corrente = *pl;
    while(corrente != NULL){
        printf("%s: ", corrente->veicolo.targa);
        if(corrente->veicolo.accessi <= 5){
            printf("%.2f\n", corrente->veicolo.accessi * 2.0);
        }
        else if(corrente->veicolo.accessi > 5 && corrente->veicolo.accessi <= 10){
            printf("%.2f\n", corrente->veicolo.accessi * 1.9);
        }
        else if(corrente->veicolo.accessi > 10){
            printf("%.2f\n", corrente->veicolo.accessi * 1.8);
        }

        corrente = corrente->next;
    }
}

void fileUltime(Lista *pl_ultime3){
    FILE *pf = fopen("ultimi3.txt", "wt");

    if(pf == NULL){
        printf("Errore apertura file di testo.\n");
        exit(5);
    }
    
    Nodo *corrente = *pl_ultime3;
    while(corrente != NULL){
        fprintf(pf, "%s\n", corrente->veicolo.targa);
        corrente = corrente->next;
    }
    fclose(pf);
}