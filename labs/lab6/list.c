#include "list.h"
#include "data.h"
#include<stdlib.h>
#include<stdio.h>

Node * createNode(Data data){
	Node * node = malloc(sizeof(Node));
	node->value = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
List * createList(){
	List * list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}
void insertData(List * list, int index, Data data){
	if(list->head == NULL){
		(*list).head = createNode(data);
		(*list).tail= (*list).head;
	}else{
		Node *node = list->head;
		if(index == 1){
			Node *newNode = createNode(data);
			newNode->next = node;
			node->prev = newNode;
			list->head = newNode;
		}else{

			int counter = 1;
			while(node->next!= NULL && counter < index){ //This will take to index just less than current index.
				node = node->next;
				counter++;
			}
	//		printf("Counter=%d index=%d\n",counter,index);
			if(index > counter){//meaning out of bound.. so add at the end.
				Node *newNode = createNode(data);
				node->next=newNode;
				newNode->prev = node;
				list->tail = newNode;
			}else{
				Node *newNode = createNode(data);
				newNode->next = node;
				newNode->prev = node->prev;

				node->prev->next = newNode;

				node->prev = newNode;
			}
		}
	}
}

void printList(List *list){
	if(list->head==NULL){
		 printf("\tCant print Empty List\n");
		return;
	}
	Node * node = list->head;
	printf("\tHead->");
        while(node!=NULL){
                printf("%d->", node->value);
                node = node->next;
        }
	printf("Tail\n");
}
void printListReverse(List *list){
	if(list->head==NULL) {
		printf("\tCant print Empty List\n");
		return;
	}
        Node * node = list->tail;
        printf("\tTail->");
        while(node!=NULL){
                printf("%d->", node->value);
                node = node->prev;
        }
        printf("Head\n");
}

void * freeList(List *list){
        freeNode((*list).head);
	list->head = NULL;
	list->tail = NULL;
        free(list);
        return NULL;
}

void freeNode(Node * node){
	Node *tempNode;
	while(node!=NULL){
		if(node->next != NULL){
			tempNode = node->next;
	//		tempNode = tempNode->next;
			node->next = NULL;
			node->prev = NULL;
			free(node);
//			node = NULL;
			node = tempNode;
			//node = node->next;
		}else{
			node->next = NULL;
			node->prev = NULL;
			free(node);
			node = NULL;
		}
	}
}
int removeData(List * list, int index){
	if(list->head==NULL){
		printf("\tList is Empty\n");
		return 0;
	}
	//Deleting Tail
	if(index == -1){
		Node *node;
		if(list->head->next == NULL){
			printf("\t Only 1 element in List\n");
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
			printf("\tList Emptied\n");
			return 0;
		}else{
			list->tail->prev->next = NULL;
			free(list->tail);
			list->tail->next= NULL;
			list->tail->prev= NULL;
			return 0;
		}
	}
	//If we have only 1 element:
	if(list->head->next == NULL){
		printf("\t Only 1 element in List\n");
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		printf("\tList Emptied\n");
		return 0;
	}else{
		Node *node = list->head;
		//Delete Head
		if(index == 1){
			node->next->prev = NULL;
			list->head = node->next;
			node->next = NULL;
			free(node);
			node= NULL;
			return 0;
		}else{
			int count = totalCount(list);
			if(index >= count){
				printf("\tIndex is out of bound, Deleting last element\n");
				Node * prevNode = list->tail->prev;
				prevNode->next= NULL;
				free(list->tail);
				list->tail=NULL;
				list->tail = prevNode;
				return 0;
			}else{
				int counter = 1;
				while(node->next->next != NULL && counter < index){
					node = node->next;
					counter++;
				}
				//printf("c=%d I=%d\n",counter, index);
				node->prev->next = node->next;
				node->next->prev = node->prev;
				free(node);
				node->next = NULL;
				node->prev = NULL;
				return 0;
			}
		}
	}
	return 1;
}
int totalCount(List *list){
	if(list->head==NULL){
		printf("\tEmpty List\n");
		return;
	}
	int count = 0;
	Node * node = list->head;
	while(node!=NULL){
		count++;
		node = node->next;
	}
	return count;
}
//Data * readData(List * list, int index);
//int Empty(List * list);
