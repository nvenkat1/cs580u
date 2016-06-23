#include<stdio.h>
#include<stdlib.h>
//#include<string.h>


#define PART_1 1
#define PART_2 1

struct Car{
	int cargo_weight;
	struct Car * next_car;
	struct Car * prev_car;
};
struct train{
	struct Car *engine;
	struct Car *carbose;
};

struct train * createTrain(){
	struct train * ptr = malloc(sizeof(struct train));
	(*ptr).engine = NULL;					//User wull forget to do this.
	ptr->carbose = NULL;	//added later Doybly
	return ptr;
}

int totalWeight(struct train *train){
	if(train->engine == NULL)return 0;
	//bookmark
	struct Car * current = (*train).engine;
	int accum = 0;
	while( (*current).next_car != NULL) {
		accum = accum + (*current).cargo_weight;
		current = current->next_car;		//otherwise infinite loop at same place.
	}
	return accum;
}
struct Car * createCar(int weight){
	struct Car  *c =  malloc(sizeof(struct Car));
	c->next_car = NULL;
	c->prev_car = NULL;		//doubly linked list add
	c->cargo_weight = weight;
	return c;
}
void insert(struct train *t, int weight/*, int index*/){
	if(t->engine == NULL){
		//(*t).engine = malloc(sizeof(struct car));		//remember next is set to junk now
		(*t).engine = createCar(weight); //constructor		//remember next is set to junk now
	}else{//or go to last element and add at last.
		struct Car * current = (*t).engine;		//set head
		int current_index;
	        while( (*current).next_car != NULL /*&& index < current_index*/) {
	                current = current->next_car;                //otherwise infinite loop at same place.
			//current_index++;
        	}
		struct Car * newNode = createCar(weight);
		current->next_car = createCar(weight);
		//current->next->prev = current;
		newNode->prev_car = current;
		//or
		//TODO: for indexx
	}
}

int read(struct train *t){
	//return last element
	if(t->engine == NULL) return -1;
	//only following will give seg falut, v/c engine is null
	struct Car * current = (*t).engine;         //set head
                while( (*current).next_car != NULL /*&& index < current_index*/) {
                        current = current->next_car;                //otherwise infinite loop at same place.
                        //current_index++;
                }
         return current->cargo_weight;
}
void deleteCar(struct train *t){
	//Deleting last node
        //return last element
        if(t->engine == NULL) return;

	//case when we have only 1 element as head following code  -> next->next ill break;
	if(t->engine->next_car ==NULL){
		free(t->engine);
		t->engine = NULL;
		//return
	}else{
	        //only following will give seg falut, v/c engine is null
        	struct Car * current = (*t).engine;         //set head
                while( (*current).next_car->next_car != NULL /*&& index < current_index*/) {
                        current = current->next_car;                //otherwise infinite loop at same place.
                        //current_index++;
                }
	         //return current->cargo_weight;
		free(current->next_car);
		current->next_car= NULL;
	}
}

int main(){

#if PART_1
	struct train myTrain1;
	struct Car cart1, cart2, cart3;

	//NEver trust user to create a trian.


	myTrain1.engine = &cart1;
	cart1.next_car = &cart2;
	cart2.next_car = &cart3;
	cart3.next_car = NULL;

	printf("total wright = %d\n", totalWeight(&myTrain1));
#endif

#if PART_2
	struct train * myTrain = createTrain();
	//insert(myTrain, /*use data structure */ , weight);
	int  i = 0;
	for(i = 0 ; i<3; i++)
	insert(myTrain, /*use data structure */ 50);

	struct train myTrain2 = *myTrain;	// no deep copy just address copy

#endif

return 0;
}
