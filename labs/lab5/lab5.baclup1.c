#include "vector.h"
#include<stdio.h>
#include<time.h>

void printVector(Vector *v){
	Data *d;
        printf("[");
	int i = 0;
	if( (*v).current_size != 0){
	        for(i= 0 ; i< ((*v).current_size -1) ; i++){
        	        d = vectorRead(v,i);
        	        //printf("(*v).array1[%d] = %d\n", i, d[i]);
        	        printf("%d,",d[i]);
       		}
		if((*v).current_size == 0 ){		//Added since, when we are trying to delete 0th element, I am only decreasing current size
			printf("]\n");			//So when we have elemet 1, I only decrease current size--, so it becomes 0
		}else{					//But here in if statement, I was directly accessing dpi[ before, added check to check
			d = vectorRead(v,i);
			printf("%d]\n",d[i]);		//current size first
		}
	}else{
		printf("]\n");
	}
}

int main(){
	int i = 0;
	srand(time(NULL));
	Vector *vector2 = createVector();
	Vector *vector3 = createVector();
	Data array1[20];
	Data array3[20];

#if DEBUG_1
	Vector *vector = createVector();
	Vector *vector1 = createVector();
	printf("size of vector = %d\n", sizeof(Vector));
	//size of main struct is 16 Bytes = (*data) [8] + (current_size) [4] + (capacity) [4]
#endif

#if DEBUG_1
	Data data;
	data.num = 5;

	Data array[5] = {1,2,3,4,5};

	printf("size of Data = %d\n", sizeof(Data));
	printf("data.num %d\n", data.num);
	//size of main struct is 16 Bytes = (*data) [8] + (current_size) [4] + (capacity) [4]
	vectorInsert(vector, 0, data);
	vectorInsert(vector, 1, data);
	vectorInsert(vector, 2, data);
	vectorInsert(vector, 3, data);
	vectorInsert(vector, 4, data);

	vectorInsert(vector1, 0, array[0]);
        vectorInsert(vector1, 1, array[1]);
        vectorInsert(vector1, 2, array[2]);
        vectorInsert(vector1, 3, array[3]);
        vectorInsert(vector1, 4, array[4]);
#endif
	//Insert Vector
	printf("\tInsert:\n\tGenerating 20 random Numbers\n");

	for( i  = 0 ; i < 20 ; i++){
		array1[i].num = rand() % 20 + 1;
		vectorInsert(vector2, i, array1[i]);
	}
	printf("[");
	for( i  = 0 ; i < 19 ; i++){
                printf("%d,", array1[i].num);
        }
	printf("%d]\n",array1[i].num);


	//Testing Read
	printf("\tReading Vector\n");
	Data *d;
	printf("[");
        for(i= 0 ; i<19 ; i++){
		d = vectorRead(vector2,i);
                //printf("(*v).array1[%d] = %d\n", i, d[i]);
		printf("%d,",d[i]);
        }
	printf("%d]\n",d[i]);

	//RemoveVector
	printf("\tDeleting Vector at 0th index for 20 rounds\n");
	for(i= 0; i<20; i++){
		vectorRemove(vector2, 0);
		printVector(vector2);
	}

	vector2 = deleteVector(vector2);


	return 0;
}
