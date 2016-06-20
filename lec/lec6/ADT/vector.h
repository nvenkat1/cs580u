#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector{
	int * data;
	unsigned int current_size;
	unsigned int capacity;
}Vector;

Vector * initVector();
void*  deleteVector(Vector *);

#endif
