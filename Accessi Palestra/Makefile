palesta: main.o accessoUtenti.o
	gcc -g -o palestra main.c accessoUtenti.c

main.o: main.c accessoUtenti.h
	gcc -c main.c

accessoUtenti.o: accessoUtenti.c accessoUtenti.h
	gcc -c accessoUtenti.c