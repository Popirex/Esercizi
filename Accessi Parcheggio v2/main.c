#include "funzioni.h"


int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Uso: %s accessi.dat", argv[0]);
        exit(1);
    }

    Lista l_veicoli;
    Lista l_ordinata;

    inizializzaLista(&l_veicoli);
    inizializzaLista(&l_ordinata);
    leggiFile(&l_veicoli, argv[1]);
    verificaAccessi(&l_veicoli, &l_ordinata);
    stampa(&l_ordinata);


    return 0;
}