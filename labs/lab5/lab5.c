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
	printf("\tInsert Test:\n\tGenerating 20 random Numbers\n");

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
	printf("\tReading Test:\n");
	Data *d;
	printf("[");
        for(i= 0 ; i<19 ; i++){
		d = vectorRead(vector2,i);
                //printf("(*v).array1[%d] = %d\n", i, d[i]);
		printf("%d,",d[i]);
        }
	printf("%d]\n",d[i]);

	//RemoveVector
	printf("\tDelete Test\n");
	printf("\tDeleting Vector at 0th index for 20 rounds\n");
	for(i= 0; i<20; i++){
		vectorRemove(vector2, 0);
		printVector(vector2);
	}

	vector2 = deleteVector(vector2);

#endif
#if DEBUG_PART_2

#if DEBUG_PART_2_1
	printf("Comparing Geomertic and Incremental Approach\n\t1.Geometric Apparoach : Capacity = Capacity * 2\n");
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
		printf("\tstart time = %ld\n", start_time);
		time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
		printf("\tstop time = %ld\n", stop_time);
		time_t final_time = stop_time - start_time;
		printf("\tfinal time = %ld\n", final_time);
#if SHOW_PROFILE_DETAIL
	printf("\tcapacity = %d, current size = %d\n",(*vector3).capacity , (*vector3).current_size);
#endif
	float ratio = (*vector3).capacity / (*vector3).current_size;
#if SHOW_PROFILE_DETAIL
	printf("\tRatio=%f\n",ratio);
#endif
	float profileTime = ratio * final_time;
	printf("\tprofileTime = %lf\n", profileTime);

	vector3 = deleteVector(vector3);

#endif
	/////////////////////////////Increamental Appariach
#if DEBUG_PART_2_2

	printf("\n\tIncreamental Apparoach: Capacity = Capacity + 1\n");
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
			vectorInsert2(vector4, i, array4[i]);
		}
	}
		gettimeofday(&stop, NULL);
		start_time = (start.tv_sec* 1000000) + start.tv_usec;
		printf("\tstart time = %ld\n", start_time);
		stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
		printf("\tstop time = %ld\n", stop_time);
		final_time = stop_time - start_time;
		printf("\tfinal time = %ld\n", final_time);
#if SHOW_PROFILE_DETAIL
	printf("\tcapacity = %d, current size = %d\n",(*vector4).capacity , (*vector4).current_size);
#endif
	float ratio4 = (*vector4).capacity / (*vector4).current_size;
#if SHOW_PROFILE_DETAIL
	printf("\tRatio=%f\n",ratio4);
#endif
	float profileTime4 = ratio4 * final_time;
	printf("\tprofileTime = %lf\n", profileTime4);

	vector4 = deleteVector(vector4);

#endif//part 2 2

#endif //part2 1
//////////////////////Part C

#if DEBUG_PART_3
        printf("\n\t3. My Apparoach : Increament with (Capacity *3)/2 + 1 \n");
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
		printf("\tstart time = %ld\n", start_time);
                stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
		printf("\tstop time = %ld\n", stop_time);
                final_time = stop_time - start_time;
		printf("\tfinal time = %ld\n", final_time);
#if SHOW_PROFILE_DETAIL
	printf("\tcapacity = %d, current size = %d\n",(*vector5).capacity , (*vector5).current_size);
#endif
	float ratio5 = (*vector5).capacity / (*vector5).current_size;
#if SHOW_PROFILE_DETAIL
        printf("\tRatio=%f\n",ratio5);
#endif
        float profileTime5 = ratio5 * final_time;
	printf("\tprofileTime = %lf\n", profileTime5);

	vector5 = deleteVector(vector5);
#endif
	return 0;
}
