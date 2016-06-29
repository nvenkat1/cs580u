P=lab8

a:$(P)

$(P):$(P).o map.o vector.o data.o city.o list.o
	gcc -g $(P).o map.o vector.o data.o city.o list.o -o $(P)

$(P).o:$(P).c map.h vector.h city.h
	gcc -g -c $(P).c

map.o:map.c map.h vector.h city.h
	gcc -g -c map.c

vector.o:vector.c vector.h data.h
	gcc -g -c vector.c

data.o:data.c data.h city.h
	gcc -g -c data.c

city.o:city.c city.h list.h
	gcc -g -c city.c

list.o:list.c list.h
	gcc -g -c list.c

r:$(P).c map.c map.h city.h city.c vector.c vector.h data.h data.c list.h list.c
	gcc $(P).c map.c city.c vector.c data.c list.c -o $(P)
	./$(P)

m:$(P).c 
	gcc -g $(P).c map.c city.c vector.c data.c list.c -o $(P)
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./$(P)

d:$(P).c map.c map.h city.c city.h vector.c vector.h data.h data.c list.h list.c
	gcc -g $(P).c map.c city.c vector.c data.c list.c -o $(P)
	gdb $(P)

c:
	rm *.o $(P)

