#ifndef LIST_H
#define LIST_H
#include "data.h"

#define DELETE_1 0
#define DELETE_2 0

typedef struct list{
	struct node *head;
	struct node *tail;
}List;

typedef struct node{
	//Data value;
	Data *value;
	struct node * next;
	struct node * prev;
}Node;

Node * createNode(Data);
List * createList();
void insertData(List * list, int index, Data value);
int removeData(List * list, int index);
Data * readData(List * list, int index);
int Empty(List * list);
void printList(List *list);
void printListReverse(List *list);
void * freeList(List *list);
void freeNode(Node * node);
int totalCount(List *list);
#endif
