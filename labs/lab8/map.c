#include "data.h"
#include "map.h"
#include "vector.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>

Map * createMap(char * filename){
	Map *map = malloc(sizeof(Map));
	//map->cityList = createList();
	map->cityVector = createVector();

	int x, y;
	char cityName[255] = {0};
	FILE * fptr = fopen(filename, "r");

	//Data data;

	int index = 0;
	while( fscanf(fptr, "%s %d %d", cityName, &x, &y)!= EOF){
		//City *city = createCity(cityName, x, y);
		//data.city = city;
		City city;
		strcpy(city.name,cityName);
		city.x = x;
		city.y = y;

		Data data;
		data.city = &city;

		vectorInsert3(map->cityVector, index, data);
		index++;
	}
	return map;
}
City* findByName(Map * map, char * cityName){
}

void printMap(Map *map){
	printVector(map->cityVector);
}

/*void printMap(Map *map){
	printList(map->cityList);
}

void * deleteMap(Map *map){
	deleteList(map->cityList);
	//freeList(map->cityList);
}*/
