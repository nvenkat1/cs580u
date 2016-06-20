P=lab5

all:$(P)

$(P):$(P).o vector.o 
	gcc -g $(P).o vector.o  -o $(P)

$(P).o:$(P).c vector.h data.h
	gcc -g -c $(P).c

vector.o:vector.c vector.h data.h
	gcc -g -c vector.c

r:$(P).c vector.c
	gcc $(P).c vector.c -o $(P)
	./$(P)

m:$(P).c vector.c
	gcc -g $(P).c vector.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c
	gcc -g $(P).c vector.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

