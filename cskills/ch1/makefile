P=ex4

all:$(P)

$(P):$(P).o
	gcc $(P).o -o $(P)

$(P).o:$(P).c
	gcc -c -Wall $(P).c

m:$(P).c
	gcc -g $(P).c -o $(P)
	valgrind --tool=memcheck --leak-check=full --show-rechable=yes --track-origi$
r:$(P).c
	gcc $(P).c -o $(P)
	./$(P)

d:
	gcc -g $(P).c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)




