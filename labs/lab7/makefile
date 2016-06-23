P=lab7

a:$(P)

$(P):$(P).o bst.o data.o
	gcc -g $(P).o bst.o data.o -o $(P)

$(P).o:$(P).c bst.h data.h
	gcc -g -c $(P).c

bst.o:bst.c bst.h data.h
	gcc -g -c bst.c

data.o:data.c bst.h data.h
	gcc -g -c data.c

r:$(P).c data.h bst.h bst.c data.c
	gcc $(P).c bst.c data.c -o $(P)
	./$(P)

m:$(P).c data.h bst.h bst.c data.c
	gcc -g $(P).c bst.c data.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c bst.c bst.h data.h data.c
	gcc -g $(P).c bst.c data.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

