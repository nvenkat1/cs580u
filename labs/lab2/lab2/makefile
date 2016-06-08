all:lab2

lab2:lab2.o
	gcc -g lab2.o -o lab2

lab2.o: lab2.c
	gcc -c lab2.c

checkmem:lab2.c
	gcc -g lab2.c -o lab2
	valgrind ./lab2

run:lab2.c
	gcc -g lab2.c -o lab2
	./lab2

defuseTheBomb:defuseMe.o bomb.o hidden.o
	gcc defuseMe.o bomb.o hidden.o -o defuseTheBomb

defuseMe.o:defuseMe.c
	gcc -g -c defuseMe.c -o defuseMe.o

bomb.o:bomb.c
	gcc -g -c bomb.c -o bomb.o

clean:
	rm lab2 lab2.o
