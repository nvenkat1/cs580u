all:person

person: person.h
	gcc person.o struct.o -o person

person.o: person.c person.h grades.h
	gcc -c person.c -o person.o

struct.o: struct.c person.h
	gcc -c structs.c -o struct.o

