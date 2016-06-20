#include "data.h"
#ifndef VECTOR_H
#define VECTOR_H

#define DEBUG_1 0

typedef struct vector{
	Data * data;
	unsigned int current_size;
	unsigned int capacity;
}Vector;

Vector * createVector();
void vectorInsert(Vector * array, int index, Data value);
Data * vectorRead(Vector * array, int index);
void vectorRemove(Vector * array, int index);
void * deleteVector(Vector *);

#endif
