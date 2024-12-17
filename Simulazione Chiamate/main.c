#include "funzioni.h"

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Uso: %s utenti.dat chiamate.txt\n", argv[0]);
        exit(1);
    }

    Lista_utenti l_utenti;
    Lista_chiamate l_chiamate;
    inizializzaListaUtenti(&l_utenti);
    inizializzaListaChiamate(&l_chiamate);
    leggiFileBinario(&l_utenti, argv[1]);
    leggiFileTesto(&l_chiamate, argv[2]);
    calcoloTariffa(&l_utenti, &l_chiamate);
    stampaChiamate(&l_utenti);


    return 0;
}