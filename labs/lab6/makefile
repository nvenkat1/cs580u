P=lab6

a:$(P)

$(P):$(P).o list.o
	gcc -g $(P).o list.o -o $(P)

$(P).o:$(P).c list.h data.h
	gcc -g -c $(P).c

list.o:list.c list.h data.h
	gcc -g -c list.c

r:$(P).c list.c data.h list.h
	gcc $(P).c list.c -o $(P)
	./$(P)

m:$(P).c list.c data.h list.h 
	gcc -g $(P).c list.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c list.c list.h data.h 
	gcc -g $(P).c list.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

