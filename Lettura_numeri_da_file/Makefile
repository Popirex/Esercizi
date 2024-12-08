lettore: main.o lettore.o
	gcc -g -o lettore main.o lettore.o

main.o: main.c lettore.h
	gcc -c -g main.c

lettore.o: lettore.c lettore.h
	gcc -c -g lettore.c