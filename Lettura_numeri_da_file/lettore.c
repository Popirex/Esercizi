#include "lettore.h"

int leggiNumeriFile( const char *nomefile, int *numeri)
{
    FILE *filepartenza = fopen(nomefile, "rt");

    if(filepartenza == NULL){
        printf("Errore apertura file di input!.\n");
        exit(1);
    }

    int conteggio=0;
    while(fscanf(filepartenza, "%d", &numeri[conteggio]) == 1 && conteggio < MAX_NUMERI){
        conteggio++;
    }
    fclose(filepartenza);
    printf("Ricevuti correttamente tutti i numeri del file!\n");
    return conteggio;

}

int somma(int *numeri, int conteggio)
{
    int somma = 0;
    for(int i = 0; i < conteggio; i++){
        somma += numeri[i];
    }
    return somma;
}

int massimo(int *numeri, int conteggio){
    int massimo = INT_MIN;
    for(int i =0; i<conteggio;i++){
        if(numeri[i]>massimo){
            massimo = numeri[i];
        }
    }
    return massimo;
}

int minimo(int *numeri, int conteggio){
    int minimo=INT_MAX;
    for(int i=0; i<conteggio;i++){
        if(numeri[i] < minimo){
            minimo = numeri[i];
        }
    }
    return minimo;
}

void stampaOutput(const char *fileoutput,int somma ,int massimo, int minimo)
{
    FILE *output_file = fopen(fileoutput, "wt");

    if(output_file == NULL){
        printf("Errore apertura file di output!\n");
        exit(2);
    }

    fprintf(output_file, "Somma: %d\nMassimo: %d\nMinimo: %d\n", somma, massimo, minimo);
    printf("La modifica del file di output e' avvenuta correttamente!\n");
    fclose(output_file);

}