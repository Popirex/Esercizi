#include "funzioni.h"

int main(int argc, char *argv[]){

    Lista l_temperature;
    inizializzaLista(&l_temperature);
    leggiFile(&l_temperature, argv[1]);
    
    return 0;
}