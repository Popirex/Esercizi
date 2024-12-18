#include "funzioni.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Uso: %s accessi.dat\n", argv[0]);
        exit(1);
    }

    Lista l_disordinata;
    Lista l_ordinata;
    Lista l_ultime3;
    inizializzaLista(&l_disordinata);
    inizializzaLista(&l_ordinata);
    inizializzaLista(&l_ultime3);
    leggiFile(&l_disordinata, argv[1], &l_ultime3);
    calcolaAccessi(&l_disordinata);
    ordinaLista(&l_disordinata, &l_ordinata);
    stampa(&l_ordinata);
    fileUltime(&l_ultime3);

    return 0;
}