utenti: main.o funzioni.o
	gcc -g -o utenti main.c funzioni.c

main.o: main.c funzioni.h
	gcc -c main.c

funzioni.o: funzioni.c funzioni.h
	gcc -c funzioni.c