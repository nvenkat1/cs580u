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
	city->edge = NULL;
	return city;
}

void createEdge(List *list, int index, Data data, int weight){
	Node * node = list->head;
	int counter = 1;
	while(node->next!=NULL &&  counter<index){
		node = node->next;
		counter++;
	}
	node->data->city->edge = malloc(sizeof(Edge));
	node->data->city->edge->city = data.city;
	node->data->city->edge->weight = weight;
}
//Assumaption : Lit index starts from 1 instead of zero Please notice.

void setAdjacent(Vector *v){
	int i=0, j=0, index=1;
	for(i=0; i < (v->current_size) ; i++){
		City *city = v->data[i].city;
		//city->adjList = malloc(sizeof(List)* (v->current_size));
		city->adjList = createList();
		insertData(city->adjList, index, v->data[i]);
		createEdge(city->adjList, index, v->data[i], 0);
		index++;

		//List *adjList = city->adjList;
		for(j=i; j < (v->current_size) ; j++){

			if(i!=j){
				//Are they in  horizontal or vertical line?
				int Ax = v->data[i].city->x;	int Ay = v->data[i].city->y;
				int Bx = v->data[j].city->x; 	int By = v->data[j].city->y;
				if(Ax==Bx || Ay==By){
					//There is a path!
					int weight;
					//check if shorted path available
					if(Ax==Bx){
						//weight = abs(Ay-By);
						insertData(city->adjList, index, v->data[j]);
						weight = abs(Ay-By);
						createEdge(city->adjList, index, v->data[j], weight);
						//city->adjList->data->city->edge->weight = abs(Ay-By);
						index++;
					}else if(Ay==By){
						//weight = abs(Ax-Bx);
						insertData(city->adjList, index, v->data[j]);
						weight = abs(Ax-Bx);
						createEdge(city->adjList, index, v->data[j], weight);
						//city->adjList->data->city->edge->weight = abs(Ax-Bx);
						index++;
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
