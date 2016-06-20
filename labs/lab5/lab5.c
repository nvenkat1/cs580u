#include "vector.h"
#include<stdio.h>
#include<time.h>
#include <time.h>/* time_t */
#include <sys/time.h>/* timeval, gettimeofday() */

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

#if DEBUG_PART_1

	Vector *vector2 = createVector();
	Data array1[20];

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

#endif
#if DEBUG_PART_2

#if DEBUG_PART_2_1
	printf("Comparing Geomertic and Incremental Approach\n\t1.Geometric Apparoach\n");
	int test[10000];
	Vector *vector3 = createVector();
	Data array3[10000];

	for( i = 0; i< 10000; i ++){
                test[i] =  rand() % 2;
                array3[i].num = rand() %100;
	}

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	for( i = 0; i< 10000; i ++){
		if(test[i] == 1){
			vectorInsert(vector3, i, array3[i]);
		}
	}
		gettimeofday(&stop, NULL);
		time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
		time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
		time_t final_time = stop_time - start_time;

	float ratio = (*vector3).capacity / (*vector3).current_size;
	printf("\t=%lf\n",ratio);
	float profileTime = ratio * final_time;
#endif
	/////////////////////////////Increamental Appariach
#if DEBUG_PART_2_2

	printf("\n\tIncreamental Apparoach\n");
	int test4[10000];
	Vector *vector4 = createVector();
	Data array4[10000];

	for( i = 0; i< 10000; i ++){
                test4[i] =  rand() % 2;
                array4[i].num = rand() %100;
	}

	//struct timeval start, stop;
	gettimeofday(&start, NULL);

	for( i = 0; i< 10000; i ++){
		if(test4[i] == 1){
	//		vectorInsert2(vector4, i, array4[i]);
		}
	}
		gettimeofday(&stop, NULL);
		start_time = (start.tv_sec* 1000000) + start.tv_usec;
		stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
		final_time = stop_time - start_time;

	float ratio4 = (*vector4).capacity / (*vector4).current_size;
	printf("\t=%lf\n",ratio4);
	float profileTime4 = ratio4 * final_time;

#endif//part 2 2

#endif //part2 1
//////////////////////Part C

#if DEBUG_PART_3
        printf("\n\t3. My Apparoach\n");
        int test5[10000];
        Vector *vector5 = createVector();
        Data array5[10000];

        for( i = 0; i< 10000; i ++){
                test5[i] =  rand() % 2;
                array5[i].num = rand() %100;
        }

        //struct timeval start, stop;
        gettimeofday(&start, NULL);

        for( i = 0; i< 10000; i ++){
                if(test5[i] == 1){
                        vectorInsert3(vector5, i, array5[i]);
                }
        }
                gettimeofday(&stop, NULL);
                start_time = (start.tv_sec* 1000000) + start.tv_usec;
                stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
                final_time = stop_time - start_time;

        float ratio5 = (*vector5).capacity / (*vector5).current_size;
        printf("\t=%lf\n",ratio5);
        float profileTime5 = ratio5 * final_time;

	//for( i = 0; i< 10000; i ++){
	//	printf("%d ", test[i]);
	//}
	//for( i = 0; i< 10000; i ++){
	//	printf("%d ", array3[i]);
	//}


	/*Data array3[5] = {1,2,3,4,5};

	vectorInsert(vector3, 1, array3[3]);
	vectorInsert(vector3, 4, array3[4]);
	vectorInsert(vector3, 0, array3[2]);
	vectorInsert(vector3, 3, array3[1]);
	vectorInsert(vector3, 2, array3[0]);

	printf("Current size = %d\n",(*vector3).current_size);
	printf("[");
        for( i  = 0 ; i < (sizeof(array3)/sizeof(Data)-1) ; i++){
                printf("%d,", array3[i].num);
        }
        printf("%d]\n",array3[i].num);

	printf("\tReading Vector\n");
	printf("Current Size = %d\n", (*vector3).current_size);
        Data *d3;
        printf("[");
        for(i= 0 ; i<(*vector3).current_size -1 ; i++){
                d3 = vectorRead(vector3,i);
                //printf("(*v).array1[%d] = %d\n", i, d[i]);
                printf("%d,",d3[i]);
        }
        printf("%d]\n",d3[i]);
	*/

#endif


	return 0;
}
