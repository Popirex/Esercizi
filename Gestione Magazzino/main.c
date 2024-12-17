#include "funzioni.h"

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Uso: %s prodotti.dat ordine.txt", argv[0]);
        exit(1);
    }

    Lista pl_prodotti;
    inizializzaLista(&pl_prodotti);

    leggiFile(&pl_prodotti, argv[1]);

    verificaProdotti(pl_prodotti, argv[2]);



    return 0;
}