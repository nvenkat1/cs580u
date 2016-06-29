#ifndef CITY_H
#define CITY_H
#include "list.h"
#include "vector.h"


typedef struct city{
	char name[255];
	int x, y;
	struct list *adjList;
	int visited;
}City;

struct edge{
	struct city *city;
	int weight;
}Edge;

struct city * createCity(char * cityNameIn, int xIn, int yIn);
void setAdjacent(Vector * );
struct list * getAdjacent(City *city);

void * deleteCity(struct city *);


#endif
