#include "map.h"
#include<stdio.h>

int main(){

	//Map * createMap(char * filename);
	Map *map = createMap("townlist2.txt");
	printMap(map);

	return 0;
}
