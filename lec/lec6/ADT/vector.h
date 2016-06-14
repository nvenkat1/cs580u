#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector{
	Data * array;
	unsigned int current_size;
	unsigned int capacity;
}Vector;

Data * initVector(Data *, int , int );
void  deleteVector(Data *);

#endif
