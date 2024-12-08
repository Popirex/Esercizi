gestione: main.o gestione.o
	gcc -g -o gestione main.o gestione.o

main.o: main.c gestione.h
	gcc -c -g main.c

gestione.o: gestione.c gestione.h
	gcc -c -g gestione.c