#include "funzioni.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Uso: %s vaccini.dat\n", argv[0]);
        exit(1);
    }

    Lista l_cani;
    Lista l_ordinata;

    inizializzaLista(&l_cani);
    inizializzaLista(&l_ordinata);
    leggiFile(&l_cani, argv[1]);
    ordinaLista(&l_cani, &l_ordinata);
    stampa(&l_ordinata);

    return 0;
}