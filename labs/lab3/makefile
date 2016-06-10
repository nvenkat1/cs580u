all:lab3

lab3:lab3.o
	gcc lab3.o -o lab3

lab3.o:lab3.c
	gcc -c lab3.c

checkmem:lab3.c
	gcc -g lab3.c -o lab3
	valgrind ./lab3

run:lab3.c
	gcc lab3.c -o lab3
	./lab3

debug:
	gcc -g lab3.c -o lab3
	gdb lab3
clean:
	rm *.o lab3
