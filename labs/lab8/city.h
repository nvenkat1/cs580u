#ifndef CITY_H
#define CITY_H
#include "list.h"

typedef struct city{
	char name[255];
	int x, y;
	struct list *adjList;
}City;


struct city * createCity(char * cityNameIn, int xIn, int yIn);

struct list * getAdjacent(City *city);


#endif
