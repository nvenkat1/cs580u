P=ex2

all:$(P)

$(P):$(P).o 
	gcc -g $(P).o  -o $(P)

$(P).o:$(P).c 
	gcc -g -c $(P).c

r:$(P).c vector.c
	gcc $(P).c -o $(P)
	./$(P)

m:$(P).c
	gcc -g $(P).c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c
	gcc -g $(P).c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

