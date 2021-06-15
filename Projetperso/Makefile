main: main.o mod.o
	gcc -o main main.o mod.o -lm
main.o: main.c mod.h
	gcc -c -Wall -g main.c -lm
mod.o: mod.c
	gcc -c -Wall -g mod.c -lm
