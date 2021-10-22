all: main.o list.o library.o
	gcc -o 00Project main.o list.o library.o
	rm *.o

main.o: main.c library.h
	gcc -c main.c

library.o: library.c library.h
	gcc -c library.c

list.o: list.c list.h
	gcc -c list.c

run:
	./00Project