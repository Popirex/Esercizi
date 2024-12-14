#include "funzioni.h"

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Uso: %s accessi.dat\n", argv[0]);
        exit(3);
    }

    Lista l1,l2;
    inizializzaListe(&l1, &l2);
    leggiFile(&l1, argv[1]);
    ordinaLista(&l1, &l2);
    stampa(&l2);

    return 0;
}