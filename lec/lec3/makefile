P=ex1

all:$(P)

$(P):$(P).o
	gcc $(P).o -o $(P)

$(P).o:$(P).c
	gcc -c $(P).c

r:$(P).c
	gcc $(P).c -o $(P)
	./$(P)

m:$(P).c
	gcc -g $(P).c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --tack-origins=yes ./$(P)

d:$(P).c
	gcc -g $(P).c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)
