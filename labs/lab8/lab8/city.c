#include "city.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

City * createCity(char * cityNameIn, int xIn, int yIn){
	City *city =  malloc(sizeof(City));
	//city->name = cityNameIn;
	strcpy(city->name, cityNameIn);
	city->x = xIn;
	city->y = yIn;
	city->adjList = NULL;
	return city;
}

List * getAdjacent(City *city){
	List * list;

	return list;
}

void * deleteCity(City * city){
	//city.name= NULL;
	//city.x = NULL;
	//city.y = NULL;
	//city.adjList = NULL;
	free(city);
	return NULL;
}
