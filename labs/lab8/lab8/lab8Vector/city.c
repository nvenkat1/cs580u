#include "city.h"
#include "vector.h"
#include "list.h"
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
	city->visited = 0;
	return city;
}

void setAdjacent(Vector *v){
	int i=0, j=0, index=0;
	for(i=0; i < (v->current_size) ; i++){
		City *city = v->data[i].city;
		//city->adjList = malloc(sizeof(List)* (v->current_size));
		city->adjList = createList();
		insertData(city->adjList, index, v->data[i]);

		//List *adjList = city->adjList;
		for(j=i; j < (v->current_size) ; j++){
			int Ax = v->data[i].city->x;	int Ay = v->data[i].city->y;
			int Bx = v->data[j].city->x; 	int By = v->data[j].city->y;

			if(i!=j){
				//Are they in  horizontal or vertical line?
				if(Ax==Bx || Ay==By){
					//There is a path!

					//check if shorted path available
					if(Ax==Bx){
						//weight = abs(Ay-By);
					}else if(Ay==By){
						//weight = abs(Ax-Bx);
					}
				}
			}
		}

	}
}

List * getAdjacent(City *city){
	city->adjList = malloc(sizeof(List));

	return city->adjList;
}

void * deleteCity(City * city){
	//city.name= NULL;
	//city.x = NULL;
	//city.y = NULL;
	//city.adjList = NULL;
	free(city);
	return NULL;
}
