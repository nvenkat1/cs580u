#include "city.h"

#include<stdio.h>
#include<stdlib.h>

City * createCity(char * cityNameIn, int xIn, int yIn){
	City *city =  malloc(sizeof(City));
	city->cityName = cityNameIn;
	city->x = xIn;
	city->y = yIn;
	city->adjList = NULL;
	return city;
}

List * getAdjacent(City *city){
	List *list;
	return list;
}
