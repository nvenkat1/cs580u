P=lab4

all:$(P)

$(P):$(P).o tournament.o
	gcc -g $(P).o tournament.o -o $(P)

$(P).o:$(P).c
	gcc -g -c $(P).c

tournament.o:tournament.c tournament.h
	gcc -c tournament.c

r:$(P).c tournament.c
	gcc $(P).c tournament.c -o $(P)
	./$(P)

m:$(P).c tournament.c
	gcc -g $(P).c tournament.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --tack-origins=yes ./$(P)

d:$(P).c
	gcc -g $(P).c tournament.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

