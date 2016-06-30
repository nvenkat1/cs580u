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

	return 0;
}
	//printf("\n\tCity name found: %s\n\t",  city->name);
	//printf("\n\tCity name found: %s\n\t",  city->name);
	//printf("\tcityName= %s has edge to cityName = \n", (*map->cityVector).data[0].city->name);
	//printf("\tcityName= %d has edge to cityName = \n", (*map->cityVector).data[0].city->adjList->head->data->city->edge->weight);
	//  (*map->cityVector).data[0].city->adjList->head->next->data->city->name);
