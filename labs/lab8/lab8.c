#include "map.h"
#include<stdio.h>

int main(){

	//Map * createMap(char * filename);
	Map *map = createMap("townlist2.txt");
	printMap(map);

	char *cityName;
	printf("\n\tEnter City Name\n\t");
	scanf("%12s", cityName);

	City *city = findByName(map, cityName);
	printf("\n\tCity name found: %s\n\t", city->name);

	return 0;
}
