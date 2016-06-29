#ifndef CITY_H
#define CITY_H

#include "list.h"
//#include "data.h"

typedef struct city{
	int x , y;
	char * cityName;
	List * adjList;
}City;

City * createCity(char * cityName, int xCoor, int yCoor);
List * getAdjacent(City *);

#endif
