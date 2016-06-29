#include "map.h"
#include<stdio.h>

int main(){

	//Map * createMap(char * filename);
	Map *map = createMap("townlist2.txt");
	printMap(map);

	setAdjacent(map->cityVector);
	return 0;
}
