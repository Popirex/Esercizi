#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rimuoviSpaziFinali(char* parola) {
    int lunghezza = strlen(parola);
    while (lunghezza > 0 && parola[lunghezza - 1] == ' ') {
        parola[lunghezza - 1] = '\0';
        lunghezza--;
    }
}

int main() {
    FILE *file;
    char nomeFile[100];
    char riga[256];

    printf("Inserisci il nome del file .dat: ");
    scanf("%s", nomeFile);

    file = fopen(nomeFile, "r+");
    if (file == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    while (fgets(riga, sizeof(riga), file)) {
        char* parola = strtok(riga, " ");
        while (parola != NULL) {
            rimuoviSpaziFinali(parola);
            printf("%s ", parola);
            parola = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
