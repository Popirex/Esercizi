#include "accessoUtenti.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Uso: %s codicifiscali.dat ingressi.txt", argv[0]);
    }
    Lista lb = NULL;
    leggiBin(&lb, argv[1], argv[2]);
    stampa(&lb);
    return 0;
}