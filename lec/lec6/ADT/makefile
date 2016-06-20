all:vector

vector:vector.o main.o
	gcc -g vector.o main.o -o vector

vector.o:vector.h vector.c
	gcc -g -c vector.c -o vector.o

main.o:main.c vector.h
	gcc -g -c main.c -o main.o

clean:
	rm *.o vector
