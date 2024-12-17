#include "funzioni.h"

int main(int argc, char *argv[]){

    Lista l_calorie;
    Lista l_pasto;
    inizializzaLista(&l_calorie);
    inizializzaLista(&l_pasto);
    leggiCibi(&l_calorie, argv[1]);
    printf("\n");
    leggiPasto(&l_pasto, argv[2]);
    printf("Calorie totali del pasto: %f\n", calorieTotali(&l_pasto, &l_calorie));
    return 0;
}
