#include "gestione.h"
void aggiungiStudente(Studente *elenco, int *num_studenti, char *nome, int eta, float media_voti)
{
    if(*num_studenti < MAX_STUDENTI){
        strcpy(elenco[*num_studenti].nome, nome);
        elenco[*num_studenti].eta = eta;
        elenco[*num_studenti].media_voti = media_voti;
        *num_studenti+=1;
    }
    else{
        printf("Siamo spiacenti ma il database risulta pieno :(\n");
    }
}

void stampaStudenti(Studente *elenco, int num_studenti)
{
    for(int i=0; i < num_studenti; i++){
        printf("Studente %d. \nNome: %s.\nEta': %d\nMedia Voti: %.3f\n\n", i+1,elenco[i].nome, elenco[i].eta, elenco[i].media_voti);
    }
}

float mediaComplessiva(Studente *elenco, int num_studenti)
{
    float media_complessiva=0.0;
    for(int i = 0; i< num_studenti; i++){
        media_complessiva += elenco[i].media_voti;
    }
    return (num_studenti > 0) ? (media_complessiva / num_studenti) : 0;
}

void esportaStudenti(Studente *elenco, int num_studenti, const char* nome_file)
{
    FILE* file = fopen(nome_file, "a");
    if(file == NULL)
    {
        printf("Errore nell'apertura del file!\n");
        return;
    }

    for(int i = 0; i < num_studenti; i++)
    {
        fprintf(file, "Nome: %s, Eta': %d, Media voti: %.2f\n", elenco[i].nome, elenco[i].eta, elenco[i].media_voti);
    }
    fclose(file);
    printf("Elenco degli studenti copiato con successo su %s", nome_file);
}

void sovrascriviLista(const char* nome_file){
    FILE* file = fopen(nome_file, "w");
    if(file == NULL){
        printf("Errore apertura file.\n");
        return;
    }
    fclose(file);
    printf("File sovrascritto con successo!\n");
}