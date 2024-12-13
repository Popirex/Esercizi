#include "funzioni.h"


int main(int argc, char *argv[])
{
    int dl;
    Lista l;
    Lista lpulita;
    inizializzaLista(&l, &dl);
    inizializzaLista(&lpulita, &dl);
    leggiFile(argv[1], &l, &dl);
    filtra(l,&lpulita, dl); 
    stampa(lpulita);
    return 0;
}