#include "data.h"
#include "map.h"
#include "list.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>

Map * createMap(char * filename){
	Map *map = malloc(sizeof(Map));
	map->cityList = createList();

	int x, y;
	char cityName[255] = {0};
	FILE * fptr = fopen(filename, "r");

	//Data data;

	int index = 1;
	while( fscanf(fptr, "%s %d %d", cityName, &x, &y)!= EOF){
		//City *city = createCity(cityName, x, y);
		//data.city = city;
		City city;
		strcpy(city.name,cityName);
		city.x = x;
		city.y = y;

		Data data;
		data.city = &city;

		insertData(map->cityList, index, data);
		index++;
	}
	return map;
}
City* findByName(Map * map, char * cityName){
}

void printMap(Map *map){
	printList(map->cityList);
}

void * deleteMap(Map *map){
	deleteList(map->cityList);
	//freeList(map->cityList);
}
