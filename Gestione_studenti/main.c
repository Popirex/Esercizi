#include "gestione.h"

int main()
{
    int scelta;
    char nome[50];
    int eta;
    float media_voti;
    Studente elenco[MAX_STUDENTI];
    int num_studenti = 0;
    printf("Benvenuto nel menu interattivo del database studenti!\n\n");
    do
    {
        printf("Selezionare la funzione che si vuole eseguire:\n Aggiungere un nuovo studente(0)\n Stampare la lista degli studenti(1)\n Visualizzare la media complessiva(2)\n  Copiare la lista studenti su un file .txt(3)\n Sovrascrivere il file lista_studenti.txt(4)\n Uscire dal programma(5)\n");
        scanf("%d", &scelta);
        printf("\n\n\n");
        switch (scelta)
        {
        case 0:
            printf("Perfetto! Per inserire un nuovo alunno dovrai fornirmi il nome, l'eta' e la sua media dei voti:\n");
            scanf("%s%d%f", nome, &eta, &media_voti);
            aggiungiStudente(elenco, &num_studenti, nome, eta, media_voti);
            printf("\n\n\n");
            break;

        case 1:
            if(num_studenti>0)
            {
                printf("Perfetto, riportata qui sotto avrai tutta la lista degli studenti: \n");
                stampaStudenti(elenco, num_studenti);
            }
            else
            {
                printf("Non è ancora stato inserito nessun studente!\n");
            }
            printf("\n\n\n");
            break;
        case 2:
            printf("Ecco a te la media complessiva dei voti di tutti gli studenti: %f\n", mediaComplessiva(elenco, num_studenti));
            printf("\n\n\n");
            break;
        case 3:
            printf("Esporto la lista su un file .txt\n");
            esportaStudenti(elenco,num_studenti, "lista_studenti.txt");
            break;
        case 4:
            printf("Sovrascrivo la lista studenti.\n");
            sovrascriviLista("lista_studenti.txt");
            break;
        case 5:
            printf("Perfetto chiudo il programma. Alla prossima!!!\n");
            printf("\n\n\n");
            break;
        default:
            printf("Per poter utilizzare il menu interattivo, devi inserire un numero compreso tra 0 e 3.\n");
            printf("\n\n\n");
            break;
        }

    } while(scelta !=5);
}