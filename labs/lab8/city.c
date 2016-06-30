#include "city.h"
#include "vector.h"
#include "list.h"
#include "map.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

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


//List * getAdjList(Data *data){
//
//	return city->adjList;
//}

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

struct city * findByNameCity(Vector *v, char *cityName){
	int i = 0;
	for(i=0; i < (v->current_size) ; i++){
		int found = strcmp(cityName, v->data[i].city->name);
		if(found ==0)
			break;
	}
	return v->data[i].city;
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
int findIndexOfCityInVector(Vector * v, City *start){
	int i=0,index = -1;
	for(i=0; i< (v->current_size); i++){
		index++;
		int result = strcmp(start->name, v->data[i].city->name);
		//if(start == v->data[i].city)
		if(result ==0)
		break;
	}
	return index;
}
//void setDistance(Data *data, int *distance, int totalDistance){
//	List *list = getAdjList(data);
//}
int findMinDistance(int *distance, int *visited){
	int min = INT_MAX;
	int index = -1, i=0;
	for(i = 0; i< (sizeof(distance)/sizeof(int)); i++){
		if(visited[i]==0){	//only non visted nodes =0 means non visted.
			if(distance[i] < min){
				min = distance[i];
				index = i;
			}
		}
	}
	return index;
}

City * findClosestCity(Map *map,int *visited,int *distance, City *preOptimal, City *start, int indexOfStart, int visitedIndexCount){
	Vector * v = map->cityVector;
	Data *data = map->cityVector->data;

	int i = 0;
	for(i=0; i< (v->current_size); i++){
	}
	List *adjList = data[indexOfStart].city->adjList;
	int sizeofAdjList = totalCount(adjList);
	for (i=2; i <= sizeofAdjList; i++){
		data = readData(adjList, i);
		int index =  findIndexOfCityInVector(v, data->city);
		distance[index] = data->city->edge->weight;
		*(preOptimal + index) = *start;
	}
	visited[indexOfStart] = ++visitedIndexCount;

	int minCityIndex = findMinDistance(distance, visited);
	return (map->cityVector->data[minCityIndex].city);
}

List * shortestPath(Map * map, City * start, City * dest){
	List * listPath = NULL;
	int max = INT_MAX, vertexCount = 0;
	//printf("\t%d\n", max);

	vertexCount = map->cityVector->current_size;
	//printf("\t%d\n", vertexCount);
	int distance[vertexCount]; //11(0-10)
	int visited[vertexCount];//11(0-10)
	int vistedIndexCount=0;
	//char preOptimal[vertexCount][255]={0};
	City preOptimal[vertexCount];
	memset( preOptimal, 0, vertexCount* sizeof(City) );

	//Initialization
	int i=0;
	for(i=0;i<vertexCount; i++){
		distance[i]=INT_MAX;
		visited[i]=0;
		//preOptimal[i]= {0};  char firstName[20]={0}
	}
	int indexOfStart = findIndexOfCityInVector(map->cityVector, start);
	int indexOfDest = findIndexOfCityInVector(map->cityVector, dest);
	int totalDistance = 0;
	distance[indexOfStart]= 0;

	//setDistance(map->cityVector->data, distance, totalDistance);
	City *city = NULL;
	int listIndex=1;
	for(city = start; city == dest ; ){
		City *closestCity =  findClosestCity(map, visited, distance, preOptimal, start, indexOfStart, vistedIndexCount);
		Data data;
		data.city = closestCity;
		insertData(listPath, listIndex++, data);
		city = closestCity;
	}
	return listPath;
}


