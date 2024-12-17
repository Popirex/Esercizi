#include "funzioni.h"

int main(int argc, char *argv[]){


    if(argc != 3){
        printf("Uso: %s calorie.dat pasto.txt\n", argv[0]);
        exit(5);
    }
    Lista l_cibo;
    Lista l_pasto;
    inizializzaLista(&l_cibo);
    inizializzaLista(&l_pasto);
    leggiFile(&l_cibo, &l_pasto, argv[1], argv[2]);
    printf("%f\n", contaCalorie(&l_cibo, &l_pasto));

    return 0;
}