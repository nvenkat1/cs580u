#include "map.h"
#include "list.h"
#include<stdio.h>

int main(){

	Map *map = createMap("townlist2.txt");
	printMap(map);

	char city1[256], city2[256];
	printf("\n\tEnter City Name\n\t");
	scanf("%255s", city1);

	printf("\n\tEnter Other City Name\n\t");
	scanf("%255s", city2);

	City *cityFrom = findByName(map, city1);
	City *cityTo = findByName(map, city2);
	List *shortestPathList = NULL;
	shortestPathList = shortestPath(map, cityFrom, cityTo);
	printShortestPathList(shortestPathList);


	shortestPathList =freeList(shortestPathList);
	map = deleteMap(map);

	return 0;
}
