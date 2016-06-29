#include "data.h"
#ifndef VECTOR_H
#define VECTOR_H

#define DEBUG_PART_1 1
#define DEBUG_PART_2 1
#define DEBUG_PART_2_1 1
#define DEBUG_PART_2_2 1
#define DEBUG_PART_3 1
#define SHOW_PROFILE_DETAIL 1

typedef struct vector{
	Data * data;
	unsigned int current_size;
	unsigned int capacity;
}Vector;

Vector * createVector();
void vectorInsert(Vector * array, int index, Data value);
void vectorInsert2(Vector * array, int index, Data value);
void vectorInsert3(Vector * array, int index, Data value);
Data * vectorRead(Vector * array, int index);
void vectorRemove(Vector * array, int index);
void * deleteVector(Vector *);
void vectorPrint(Vector *);
#endif
