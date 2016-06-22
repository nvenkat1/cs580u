P=lab6

a:$(P)

$(P):$(P).o list.o data.o
	gcc -g $(P).o list.o data.o -o $(P)

$(P).o:$(P).c list.h data.h
	gcc -g -c $(P).c

list.o:list.c list.h data.h
	gcc -g -c list.c

data.o:data.c list.h data.h
	gcc -g -c data.c

r:$(P).c list.c data.h list.h data.c
	gcc $(P).c list.c data.c -o $(P)
	./$(P)

m:$(P).c list.c data.h list.h data.c
	gcc -g $(P).c list.c data.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c list.c list.h data.h data.c
	gcc -g $(P).c list.c data.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

