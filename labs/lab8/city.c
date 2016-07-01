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

void printAdjList(Vector *v){
	int i = 0;
	for(i =0; i< (v->current_size); i++){
		printf("%i.%s->", i+1,  v->data[i].city->name);

		printList(v->data[i].city->adjList);

	}
}

struct city * findByNameCity(Vector *v, char *cityName){
	int i = 0;
	for(i=0; i < (v->current_size) ; i++){
		int found = strcmp(cityName, v->data[i].city->name);
		if(found ==0)
			return v->data[i].city;
			//break;
	}
	printf("\n\tInvalid name Entered!\n");
	return NULL;
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
/*
char * getNamefromIndex(int parent, Vector *v){
	int i=0;
	for(i=0; i< (v->current_size); i++){
		if(parent[i]
	}
}
*/
int findMinDistance(int *distance, int *visited){
	int min = INT_MAX;
	int index = -1, i=0;
	//for(i = 0; i< (sizeof(distance)/sizeof(int)); i++){
	for(i = 0; i< 11; i++){
		if(visited[i]==0){	//only non visted nodes =0 means non visted.
			if(distance[i] < min){
				min = distance[i];
				index = i;
			}
		}
	}
	return index;
}
void copyPreviousDistance(int *distance, int * visited){
	int i=0;
	for(i=0; i<11; i++){
		if(visited[i] ==0){ //IF its visited keep the value
			distance[i] = INT_MAX;
		}
	}
}

City * findClosestCity(Map *map,int *visited,int *distance, int *parent, City *start, int indexOfStart, int visitedIndexCount, int sourceWeight, int indexOfDest){
	Vector * v = map->cityVector;
	Data *data = map->cityVector->data;
	int i = 0;
	int destFound = 0;

	//STEP1 : COPY ALL PREVIOUS VALUES OF DISTANCES if only visited
	//copyPreviousDistance(distance, visited);

	//STEP2: FIND ADJACENT NODES
	List *adjList = data[indexOfStart].city->adjList;
	int sizeofAdjList = totalCount(adjList);

	//STEP3: UPDATE DISTANCE AND PARENT IF (sourceWeight + WEIGHT TO NODE) < PREVIOUS WEIGHT
	for (i=2; i <= sizeofAdjList; i++){
		data = readData(adjList, i);
		int index =  findIndexOfCityInVector(v, data->city);
		int EdgeWeight = data->city->edge->weight;
		if(visited[index] == 0){
			if( sourceWeight + EdgeWeight < distance[index]){
				distance[index] = sourceWeight + EdgeWeight;
				parent[index] = findIndexOfCityInVector(v, start);
				if(index == indexOfDest){
					 destFound=1;
					 break;
				}
			}
		}
	}
	//STEP4: FIND MINIMUM AMOUNT ALL EDGES | SCAN IN DISTANCE ARRAY
	if( destFound == 1){
		int minCityIndex = indexOfDest;
		visited[minCityIndex] = visitedIndexCount;
		//copyPreviousDistance(distance, visited);
		return (map->cityVector->data[minCityIndex].city);
	}
	int minCityIndex = findMinDistance(distance, visited);
	visited[minCityIndex] = visitedIndexCount;

	return (map->cityVector->data[minCityIndex].city);
}

List * shortestPath(Map * map, City * start, City * dest){
	List * listPath = createList();
	int max = INT_MAX, vertexCount = 0;
	vertexCount = map->cityVector->current_size;
	int i=0, distance[vertexCount], visited[vertexCount], parent[vertexCount];
	static int visitedIndexCount = 0;

	for(i=0;i<vertexCount; i++){
		distance[i]=INT_MAX;
		visited[i]=0;
		parent[i] = -1;
	}

	int indexOfStart = findIndexOfCityInVector(map->cityVector, start);
	int indexOfDest = findIndexOfCityInVector(map->cityVector, dest);
	int currentStart = indexOfStart;
	int totalDistance = 0, sourceWeight = 0;

	distance[indexOfStart]= 0;
	visited[indexOfStart] = ++visitedIndexCount;

	City *city = NULL;
	Data data;
	data.city = start;
	int listIndex=1;
	insertData(listPath, listIndex++, data);
	city = start;
	int nullCheckCount = 0;
	while(city!= dest){
		if(nullCheckCount >=9){
			printf("\n\tCan not reach destination City\n");
			return NULL;
			//exit(0);
		}
		City *closestCity =  findClosestCity(map, visited, distance, parent, city, currentStart, ++visitedIndexCount, sourceWeight, indexOfDest);
		currentStart = findIndexOfCityInVector(map->cityVector, closestCity);
		sourceWeight = distance[currentStart];
		data.city = closestCity;
		insertData(listPath, listIndex++, data);
		city = closestCity;
		nullCheckCount++;
	}
	/*for(i=0; i<vertexCount;i++){
		if(visited[i]!=0){
			printf("\tVisited  Distance  Parent\n");
			printf("\t%-9d%-10d%-10s\n", visited[i], distance[i], map->cityVector->data[i].city->name);
		}
	}*/
	bubbleSort(distance, visited, map->cityVector, vertexCount);
	return listPath;	//TODO: disallocate this!!!!!
}

void bubbleSort(int * distance, int * visited, Vector *v, int vertexCount){
	int i = 0 , j = 0, n = 0, swap, swap1, swap2;
	Data data;
	for (i=0; i<(vertexCount-1); i++){
	    for (j=0 ; j<(vertexCount-i-1); j++){
	      if (visited[j] > visited[j+1]){ /* For decreasing order use < */
			swap = visited[j];
			swap1 = distance[j];
			data = v->data[j];
		        visited[j]   = visited[j+1];
		        distance[j]   = distance[j+1];
		        v->data[j]   = v->data[j+1];

		        visited[j+1] = swap;
		        distance[j+1] = swap1;
		        v->data[j+1] = data;
	      }
	    }
	}
	printf("\n\n\tPrinting in sorted!\n\n");
	int flag =0;
	for(i=0; i<vertexCount;i++){
		if(visited[i]!=0){
			if(flag == 0){
				//printf("\tVisited  Distance    Parent\n");
				printf("\tVisited  Parent      Distance\n");
				flag = 1;
			}
			//printf("\t%-10d%-10d%-10s\n", visited[i], distance[i], v->data[i].city->name);

			printf("\t%-9d%-12s%-2d\n", visited[i], v->data[i].city->name, distance[i]);
		}
	}
	printf("\n\n");

}
