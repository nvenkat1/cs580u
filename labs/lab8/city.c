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
		int N=0, S=0, E=0, W=0, NIndex=-1, SIndex=-1, EIndex=-1, WIndex=-1;
		int NWeight=-1, SWeight=-1, EWeight=-1, WWeight=-1;


		City *city = v->data[i].city;
		city->adjList = createList();
		insertData(city->adjList, index, v->data[i]);
		createEdge(city->adjList, index, v->data[i], 0);
		//v->data[i].weight = 0;
		index++;

		for(j=0; j < (v->current_size) ; j++){
			//printf("%d%d\n",i,j);
			if(i!=j){
				//Are they in  horizontal or vertical line?
				int Ax = v->data[i].city->x; 	int Bx = v->data[j].city->x;
				int Ay = v->data[i].city->y; 	int By = v->data[j].city->y;
				if(Ax==Bx || Ay==By){ 	//There is a path
					int weight;
					//check if shorted path available
					if(Ax==Bx){
						weight = abs(Ay-By);
						if(Ay>By){// B is South to A
                                                        if(S==0){ //if South side not has been added add one edge.
                                                                insertData(city->adjList, index, v->data[j]);
                                                                createEdge(city->adjList, index, v->data[j], weight);
                                                                SIndex = index; SWeight = weight;
                                                                index++;
                                                                S = 1;
                                                        }else if(SWeight < weight){ //if old weight is less, do nothing
                                                                continue;
                                                        }else{//Means new weight is less, remove old.
								if(SIndex == index){
                                                        	        int result = removeData(city->adjList, -1);
								}else{
                                                        	        int result = removeData(city->adjList, SIndex);
								}
                                                                index--;
                                                                insertData(city->adjList, SIndex, v->data[j]);
                                                                createEdge(city->adjList, SIndex, v->data[j], weight);
                                                                SIndex = index; SWeight = weight;
                                                                index++;
                                                                S = 1;

                                                        }
                                                }else{//B is on North of A
                                                        if(N==0){ //if North side not has been added add one edge.
                                                                insertData(city->adjList, index, v->data[j]);
                                                                createEdge(city->adjList, index, v->data[j], weight);
                                                                NIndex = index; NWeight = weight;
                                                                index++;
                                                                N = 1;
                                                        }else if(NWeight < weight){ //if old weight is less, do nothing
                                                                continue;
                                                        }else{//Means new weight is less, remove old.
								if(SIndex == index){
                                                        	        int result = removeData(city->adjList, -1);
								}else{
	                                                                int result = removeData(city->adjList, NIndex);
								}
                                                                index--;
                                                                insertData(city->adjList, NIndex, v->data[j]);
                                                                createEdge(city->adjList, NIndex, v->data[j], weight);
                                                                NIndex = index; NWeight = weight;
                                                                index++;
                                                                N = 1;

                                                        }
                                                }

					}else if(Ay==By){
						weight = abs(Ax-Bx);
						if(Ax>Bx){// B is on West of A
							if(W==0){ //if West side not has been added add one edge.
								insertData(city->adjList, index, v->data[j]);
								createEdge(city->adjList, index, v->data[j], weight);
								WIndex = index; WWeight = weight;
								index++;
								W = 1;
							}else if(WWeight < weight){ //if old weight is less, do nothing
								continue;
							}else{//Means new weight is less, remove old.
								if(SIndex == index){
                                                        	        int result = removeData(city->adjList, -1);
								}else{
									int result = removeData(city->adjList, WIndex);
								}
								index--;
								insertData(city->adjList, WIndex, v->data[j]);
								createEdge(city->adjList, WIndex, v->data[j], weight);
								WIndex = index; WWeight = weight;
								index++;
								W = 1;

							}
						}else{//B is on East of A
							if(E==0){ //if West side not has been added add one edge.
                                                                insertData(city->adjList, index, v->data[j]);
                                                                createEdge(city->adjList, index, v->data[j], weight);
                                                                EIndex = index; EWeight = weight;
                                                                index++;
                                                                E = 1;
                                                        }else if(EWeight < weight){ //if old weight is less, do nothing
                                                                continue;
                                                        }else{//Means new weight is less, remove old.
								if(SIndex == index){
                                                        	        int result = removeData(city->adjList, -1);
								}else{
	                                                                int result = removeData(city->adjList, EIndex);
                                                                }
								index--;
                                                                insertData(city->adjList, EIndex, v->data[j]);
                                                                createEdge(city->adjList, EIndex, v->data[j], weight);
                                                                EIndex = index; EWeight = weight;
                                                                index++;
                                                                E = 1;

                                                        }
						}
					}
				}
			}
		}//For J
		multipleVertexOnYAxisFlag = multipleVertexOnXAxisFlag = -1;
		cachedWeightYAxis = cachedWeightXAxis = -1;
		index=1;
	}//For I
}

List * getAdjacent(City *city){
	city->adjList = malloc(sizeof(List));

	return city->adjList;
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

void deleteEdge(struct edge *edge){
	free(edge);
	edge->city = NULL;
	edge = NULL;
}
void * deleteCity(City * city){
	deleteEdge(city->edge);
	if(city->adjList !=NULL){
		if(city->adjList->head != NULL)
			city->adjList = freeList(city->adjList);
	}
	free(city);
	city->adjList = NULL;
	city->edge= NULL;
	return NULL;

}
