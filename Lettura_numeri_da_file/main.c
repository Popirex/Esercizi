#include "lettore.h"

int main(int argc, char *argv[])
{
    int numeri[MAX_NUMERI];

    if(argc != 3){
        printf("Hai sbagliato qualcosa nel comando: ./lettore numeri.txt risultato.txt\n");
        exit(3);
    }

    if(argv[1] == NULL){
        printf("Ti sei dimenticato di inserire il file di input!!\n");
        exit(4);
    }

    if(argv[2] == NULL){
        printf("Ti sei dimenticato di inserire il file di output!!\n");
        exit(5);
    }

    const char *fileinput = argv[1];
    const char *fileoutput = argv[2];



    int conteggio = leggiNumeriFile(fileinput, numeri);
    stampaOutput(fileoutput, somma(numeri, conteggio), massimo(numeri, conteggio), minimo(numeri, conteggio));

    return 0;
}