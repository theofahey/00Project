all: main.o list.o
	gcc -o 00Project main.o list.o
	rm *.o

main.o: main.c list.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

run:
	./00Project