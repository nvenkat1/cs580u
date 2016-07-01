#ifndef CITY_H
#define CITY_H
#include "list.h"
#include "vector.h"


typedef struct city{
	char name[255];
	int x, y;
	struct list *adjList;
	int visited;
	struct edge * edge;
}City;

struct edge{
	struct city *city;
	int weight;
}Edge;

struct city * createCity(char * cityNameIn, int xIn, int yIn);
void setAdjacent(Vector * );
struct list * getAdjacent(City *city);
struct city * findByNameCity(Vector *v, char *cityName);
void setAdjacent(Vector *v);
void * deleteCity(struct city *);
void deleteEdge(struct edge *);
void bubbleSort(int *, int*, Vector *, int);
void printAdjList(Vector *v);
struct city * findByNameCity(Vector *v, char *cityName);
int findIndexOfCityInVector(Vector * v, City *start);
int findMinDistance(int *distance, int *visited);
#endif
