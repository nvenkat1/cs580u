#include "list.h"
#include "data.h"
#include<stdlib.h>
#include<stdio.h>

Node * createNode(Data data){
	Node * node = malloc(sizeof(Node));
	//node->value = data;
	node->value = initData(data.num);
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
	if(list ==  NULL) return;
	if(list->head==NULL){
		 printf("\tCant print Empty List!!\n\n");
		return;
	}
	Node * node = list->head;
	printf("\t[Head]->");
        while(node!=NULL){
                printf("[%d]->", *(node->value));
                node = node->next;
        }
	printf("[Tail]\n");
}
void printListReverse(List *list){
	if(list->head==NULL) {
		printf("\tCant print Empty List!!\n\n");
		return;
	}
        Node * node = list->tail;
        printf("\t[Tail]->");
        while(node!=NULL){
                printf("[%d]->", *(node->value));
                node = node->prev;
        }
        printf("[Head]\n");
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
			//free((*node).value);
			deleteData((*node).value);
			node->value = NULL;
			node->next = NULL;
			node->prev = NULL;
			free(node);
			node = NULL;
			node = tempNode;
			//node = node->next;
		}else{
			//free((*node).value);
			deleteData((*node).value);
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
			//free(list->head);	//commmented this 1	//-
		//Added Later 2
			deleteData( (*(*list).head).value );	 //+
                        (*(*list).head).value = NULL;		 //+
		//
			list->head = NULL;
			list->tail = NULL;
		//Added later 3
			free(list);				 //+
			list=NULL;				 //+
		//
			printf("\tList Emptied\n");
			return 0;
		}else{
		//Added later 1
			node = list->tail->prev;		//+
			node->next = NULL;			//+
			deleteData((*(*list).tail).value);	//+
			(*(*list).tail).value = NULL;		//+
			list->tail->next = NULL;		//+
			list->tail->prev = NULL;		//+
			list->tail = NULL;			//+
			list->tail = node;			//+
		//
		//OLD-Uncomment this if doenst work!
		/*	list->tail->prev->next = NULL;
			free(list->tail);
			list->tail->next= NULL;
			list->tail->prev= NULL; */
		//
			return 0;
		}
	}
	//If we have only 1 element:
	if(list->head->next == NULL){
		printf("\t Only 1 element in List\n");
	//Added Later
		deleteData( (*(*list).head).value);  	//+
		(*(*list).head).value = NULL;		//+
	//
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	//Added Later
		//free(list);				 //+
		list=NULL;				 //+
	//
		printf("\tList Emptied\n");
		return 0;
	}else{
		Node *node = list->head;
		//Delete Head
		if(index == 1){
			node->next->prev = NULL;
			list->head = node->next;
			//Added Later
			deleteData((*node).value);	  	//+
			(*node).value = NULL;			//+
			//
			node->next = NULL;
			node->prev = NULL;
			free(node);
			node= NULL;
			return 0;
		}else{
			int count = totalCount(list);
			if(index >= count){
				printf("\tIndex is out of bound, Deleting last element\n");
				Node * prevNode = list->tail->prev;
				prevNode->next= NULL;
		//Added later
 				deleteData((*(*list).tail).value);	//+
				(*(*list).tail).value = NULL;		//+
				list->tail->next = NULL;		//+
				list->tail->prev = NULL;		//+
		//

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
				//Added Later
				deleteData((*node).value);	  	//+
				(*node).value = NULL;			//+
				node->next = NULL;
				node->prev = NULL;
				free(node);
				node= NULL;
				//
				//free(node);
//				node->next = NULL;
//				node->prev = NULL;
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
Data * readData(List * list, int index){
	if(list->head==NULL){
		printf("\tEmpty List\n");
		return;
	}
	if(index == 1){
		return list->head->value;
	}
	int count = totalCount(list);
	if(index == count){
		return list->tail->value;
	}else if( index > count){
		printf("\tIndex out of bound\n\tReturning Last element\n");
		return list->tail->value;
	}else{

		count = 1;
		Node * node = list->head;
		while(node->next!= NULL && count < index) {
			count ++;
			node = node->next;
		}
		return node->value;
	}
}
int Empty(List * list1){
	int result = -1;
	if(list1->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
	printf("\nDeleting List at Random Index\n");
        while(list1!=NULL){
                int index = rand() % 25 + 1;
                printf("\n\tDeleting at index = %d\n", index-1);
                result = removeData(list1, index);
                printList(list1);
                if(list1->head==NULL) break;
        }
	return 0;
}
int searchForward(List * list, int num){
	if(list->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
	int index = -1;
	Node *node = list->head;
	while(node->next!=NULL){
		index++;
		if( (*(*node).value).num == num){
			return index;
		}
		node = node->next;
	}
	return -1;
}

int searchBackward(List * list, int num){
        if(list->head==NULL){
                printf("\tEmpty List\n");
                return 1;
        }
        int index = -1;
        Node *node = list->tail;
        while(node->prev!=NULL){
                index++;
                if( (*(*node).value).num == num){
                        return index;
                }
                node = node->prev;
        }
        return -1;
}
