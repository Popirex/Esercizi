cube: main.o cube.o
	gcc -g -o cube main.c cube.c -lSDL2 -lm

main.o: main.c cube.h
	gcc -c main.c

cube.o: cube.c cube.h
	gcc -c cube.c