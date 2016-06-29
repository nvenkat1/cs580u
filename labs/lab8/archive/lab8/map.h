#ifndef MAP_H
#define MAP_H

#include "list.h"
//#include "vector.h"
#include "city.h"


typedef struct map{
	List * cityList;	//Vector *cities;
	//Vector * cityVector;
}Map;

Map * createMap(char * filename);
City* findByName(Map * map, char * cityName);
void printMap(Map *);

#endif
