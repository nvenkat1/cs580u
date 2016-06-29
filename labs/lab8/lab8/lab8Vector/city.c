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
		int multipleVertexOnXAxisFlag = -1, cachedWeightXAxis = -1;	//MVFF=-1 (initial) =0 (set when 1Vertex), =1(Multiple Found)
		int multipleVertexOnYAxisFlag = -1, cachedWeightYAxis = -1;	//MVFF=-1 (initial) =0 (set when 1Vertex), =1(Multiple Found)
		int storedXIndex = -1, storedYIndex = -1;				//store this index b/c if in future less weight found, delete node at this stored index.
		City *city = v->data[i].city;
		city->adjList = createList();
		insertData(city->adjList, index, v->data[i]);
		createEdge(city->adjList, index, v->data[i], 0);
		index++;

		for(j=i; j < (v->current_size) ; j++){
			//printf("%d%d\n",i,j);
			if(i!=j){
				//Are they in  horizontal or vertical line?
				int Ax = v->data[i].city->x;	int Ay = v->data[i].city->y;
				int Bx = v->data[j].city->x; 	int By = v->data[j].city->y;
				if(Ax==Bx || Ay==By){ 	//There is a path
					int weight;
					//check if shorted path available
					if(Ax==Bx){
						weight = abs(Ay-By);

						if(multipleVertexOnYAxisFlag == 0){
							if(cachedWeightYAxis < weight){
								continue;
							}else{//if current weight is less, remove previous one.
                                                                int result = removeData(city->adjList, storedYIndex);
								index--;
                                                        }
						}
						insertData(city->adjList, index, v->data[j]);
						createEdge(city->adjList, index, v->data[j], weight);
						multipleVertexOnYAxisFlag = 0;
						cachedWeightYAxis = weight;
						storedYIndex = index;
						index++;
					}else if(Ay==By){
						weight = abs(Ax-Bx);

						if(multipleVertexOnXAxisFlag == 0){
							if(cachedWeightXAxis < weight){
								continue;
							}else{//if current weight is less, remove previous one.
								int result = removeData(city->adjList, storedXIndex);
							}
						}

						insertData(city->adjList, index, v->data[j]);
						createEdge(city->adjList, index, v->data[j], weight);
						multipleVertexOnXAxisFlag = 0;
						cachedWeightXAxis =  weight;
						storedXIndex = index;
						index++;
					}
				}
			}
		}//For J
		multipleVertexOnYAxisFlag = multipleVertexOnXAxisFlag = -1;
		cachedWeightYAxis = cachedWeightXAxis = -1;
	}//For I
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
void printAdjList(Vector *v){
	int i = 0;
	for(i =0; i< (v->current_size); i++){
		printf("%i.%s->", i+1,  v->data[i].city->name);

		printList(v->data[i].city->adjList);
		//Node *node =  v->data[i].city->adjList->head;
		//while(node!=NULL){
		//}

	}
}
